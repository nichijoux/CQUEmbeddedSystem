#include <stdio.h>
#include "DS1302.h"
#include "KEYS.h"
#include "LED.h"
#include "xil_mmu.h"
#include "GicAndTimer.h"

//进制OCM最后64KB的cache属性并唤醒CPU1
void remapOCMAddr();

int main(int argc,char** argv){
	print("hello world 20191692\n\r");
	//唤醒CPU1
	remapOCMAddr();

	int status = XST_SUCCESS;
	//GIC和私有定时器
	XScuGic gic;
	//初始化GIC(通用中断控制器)
	status = initScuGicDevice(&gic);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//中断异常注册
	initScuGicException(&gic);

	XScuTimer timer;
	//初始化CPU0的私有定时器
	status = initPrivateTimerDevice(&timer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//数码管的GPIO
	XGpio gpioLED;
	status = initLEDDevice(&gpioLED);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	gpioLEDAndTimer ledAndTimer;
	ledAndTimer.gpioLED = &gpioLED;
	ledAndTimer.timer = &timer;
	//初始化LED的中断
	status = setupLEDInterrupt(&gic,&ledAndTimer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//矩阵键盘的GPIO
	XGpio gpioKEYS;
	status = initKeysDevice(&gpioKEYS);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//注册键盘中断
	status = setupKEYSInterrupt(&gpioKEYS,&gic);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//DS1302的GPIO
	XGpio gpioDS1302;
	status = initDS1302Device(&gpioDS1302);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//读取闹钟设定
	for(int i = 0;i < 4;i++){
		setClockHour[i] = readDS1302Byte(&gpioDS1302,
				getDS1302_CLOCK_HOUR(i));
		setClockMinute[i] = readDS1302Byte(&gpioDS1302,
				getDS1302_CLOCK_MINUTE(i));
		setClockSecond[i] = readDS1302Byte(&gpioDS1302,
				getDS1302_CLOCK_SECOND(i));
		setClockMusic[i] = readDS1302Byte(&gpioDS1302,
				getDS1302_CLOCK_CLOCKMUSIC(i));
		if(setClockMusic[i] > 3) setClockMusic[i] = 3;
	}

	//不断扫描键盘
	while(true){
		solveKeysEvent(&gpioKEYS,readKeys(&gpioKEYS,&gic),&gpioDS1302,&gic);

		//读取时间判断是否达到闹钟
		u8 hour = readDS1302Byte(&gpioDS1302,DS1302_HOUR);
		hour &= HOUR_MASK;
		u8 minute = readDS1302Byte(&gpioDS1302,DS1302_MINUTE);
		minute &= MINUTE_MASK;
		u8 second = readDS1302Byte(&gpioDS1302,DS1302_SECOND);
		second &= SECOND_MASK;

		//判断是否达到闹钟时间
		for(int i = 0;i < 4;i++){
			if(hour == setClockHour[i] &&
					minute == setClockMinute[i] &&
					second == setClockSecond[i]){
				OCMBuffer[CLOCK_MUSIC] = setClockMusic[i];
				OCMBuffer[INTERRUPT_CPU1] = 1;
				break;
			}
		}

		if(isShowTime == LED_SHOW_TIME && !isDebug){
			loadTime(hour,minute,second);
		}else if(isShowTime == LED_SHOW_YEAR && !isDebug){
			u8 year = readDS1302Byte(&gpioDS1302,DS1302_YEAR);
			year &= YEAR_MASK;
			u8 month = readDS1302Byte(&gpioDS1302,DS1302_MONTH);
			month &= MONTH_MASK;
			u8 date = readDS1302Byte(&gpioDS1302,DS1302_DATE);
			date &= DATE_MASK;
			loadTime(year,month,date);
		}else if(isShowID){
			u8 studentID[8];
			for(int i = 0;i < 8;i++)
				studentID[i] = readDS1302Byte(&gpioDS1302,getDS1302RAM(i));
			for(int i = 0;i < 8;i++)
				displayBuffer[i] = segmentsCode[studentID[i]];
		}
	}
	return 0;
}

void remapOCMAddr()
{
    //禁用OCM的cache属性
    // S=b1 TEX=b100 AP=b11, Domain=b1111, C=b0, B=b0
    Xil_SetTlbAttributes(0xFFFF0000,0x14de2);
    //CPU1_START_UP_REG = 0xFFFFFFF0, CPU1_START_ADDRRESS = 0x20000000);
    Xil_Out32(CPU1_START_UP_REG, CPU1_START_ADDRRESS);
    dmb(); //waits until write has finished
    sev();
    dmb(); //waits until write has finished
}

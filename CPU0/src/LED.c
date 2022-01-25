#include "LED.h"

//七段数码管0~E
const u8 segmentsCode[16] = {
		0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
		0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71
};

//displayBuffer,用于七段数码管的显示buffer
volatile u8 displayBuffer[8] = {
		0X3F,0X3F,0X40,0X3F,0X3F,0X40,0X3F,0X3
};

//displayIndex,当前正在显示第几个数字
volatile u8 displayIndex = 0;
//可显示的位置(bit1 为可显示,bit0 为关闭)
volatile u8 viewIndex = 0xFF;
//正在闪烁的位置(默认先设置最后两位)
volatile u8 twinkleIndex[2] = {
		6,7
};
//要闪烁的位置计数
volatile u32 twinkleCount = 0;

//初始化GPIO设备
int initLEDDevice(XGpio* gpioLED){
	int status = XST_SUCCESS;
	status = XGpio_Initialize(gpioLED,LEDS_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//设置GPIOLED的方向
	XGpio_SetDataDirection(gpioLED,RED_LED_CHANNEL,0);
	XGpio_SetDataDirection(gpioLED,SEG_LED_CHANNEL,0);
	return XST_SUCCESS;
}

//中断函数注册
int setupLEDInterrupt(XScuGic* gic,gpioLEDAndTimer* ledAndTimer){
	int status = XST_SUCCESS;
	XScuTimer* timer = ledAndTimer->timer;
	//timer中断
	status = XScuGic_Connect(gic,PRIVATE_TIMER_INTERRUPT_ID,
			(Xil_ExceptionHandler)ledInterruptHandler,
			ledAndTimer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//允许私有定时器(29号)中断
	XScuGic_Enable(gic,PRIVATE_TIMER_INTERRUPT_ID);
	XScuTimer_EnableInterrupt(timer);
	//允许私有定时器自动重装
	XScuTimer_EnableAutoReload(timer);
	//重载寄存器
	XScuTimer_LoadTimer(timer,LED_TIMER_VALUE);
	//开始timer
	XScuTimer_Start(timer);
	return status;
}

//定时显示七段数码管的定时器函数、
void ledInterruptHandler(void* callbackRef){
	gpioLEDAndTimer* ledAndTimer = (gpioLEDAndTimer*)callbackRef;
	XGpio* gpioLED = ledAndTimer->gpioLED;
	XScuTimer* timer = ledAndTimer->timer;
	//如果定时器到期
	if(XScuTimer_IsExpired(timer)){
		//清除中断状态
		XScuTimer_ClearInterruptStatus(timer);
		displayIndex = (displayIndex + 1) % 8;
		u8 ledBUS0 = displayIndex < 4 ? displayBuffer[displayIndex] : 0;
		u8 ledBUS1 = displayIndex >= 4 ? displayBuffer[displayIndex] : 0;
		//一次只显示1位
		u8 ledSel = ~(0xFF & (1 << displayIndex));
		if(isDebug &&
					(displayIndex == twinkleIndex[0] ||
								displayIndex == twinkleIndex[1])){
			twinkleCount = (twinkleCount + 1) % 600;
			if(twinkleCount < 300){
				XGpio_DiscreteWrite(gpioLED,SEG_LED_CHANNEL,
						mergeLED(ledBUS0,ledBUS1,ledSel));
			}else{
				//灭灯
				XGpio_DiscreteWrite(gpioLED,SEG_LED_CHANNEL,
						mergeLED(ledBUS0,ledBUS1,0xFF));
			}
		}else{
			XGpio_DiscreteWrite(gpioLED,SEG_LED_CHANNEL,
					mergeLED(ledBUS0,ledBUS1,ledSel));
		}
	}
}

//加载displayBuffer
void loadTime(u8 number1,u8 number2,u8 number3){
	displayBuffer[0] = segmentsCode[(number1 >> 4) & 0x0F];
	displayBuffer[1] = segmentsCode[number1 & 0x0F];
	displayBuffer[2] = 0x40;
	displayBuffer[3] = segmentsCode[(number2 >> 4) & 0x0F];
	displayBuffer[4] = segmentsCode[number2 & 0x0F];
	displayBuffer[5] = 0x40;
	displayBuffer[6] = segmentsCode[(number3 >> 4) & 0x0F];
	displayBuffer[7] = segmentsCode[number3 & 0x0F];
}

//mergeLED,24位segmentLED
inline u32 mergeLED(u8 ledBus0,u8 ledBus1,u8 ledSel){
	return (((u32)ledBus0) + ((u32)ledBus1 << 8) + ((u32)ledSel << 16));
}

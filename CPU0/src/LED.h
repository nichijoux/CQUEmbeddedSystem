#ifndef _LED_H_
#define _LED_H_

#include "xplatform_info.h"
#include "zhmacro.h"
#include "KEYS.h"

//led设备
#define LEDS_DEVICE_ID XPAR_GPIO_LEDS_DEVICE_ID

#define RED_LED_CHANNEL CHANNEL1
#define SEG_LED_CHANNEL CHANNEL2

#define LED_SHOW_TIME	1
#define LED_SHOW_YEAR	2

//LED_DELAY
#define LED_DELAY 			100000
#define LED_TIMER_VALUE		0x14585

//用于回调函数的结构
typedef struct gpioLEDAndTimer{
	XScuTimer* timer;
	XGpio* gpioLED;
}gpioLEDAndTimer;

//在.c中初始化
//七段数码管0~E
extern const u8 segmentsCode[];
//displayBuffer,用于七段数码管的显示buffer
extern volatile u8 displayBuffer[];
//当前正在显示哪一个数字
extern volatile u8 displayIndex;
//正在闪烁的位置
extern volatile u8 twinkleIndex[2];
//要闪烁的位置计数
extern volatile u32 twinkleCount;

//LED API

//GPIO初始化
int initLEDDevice(XGpio* gpioLED);
//中断函数注册
int setupLEDInterrupt(XScuGic* gic,gpioLEDAndTimer* ledAndTimer);
//定时显示七段数码管的定时器函数
void ledInterruptHandler(void* callbackRef);
//加载displayBuffer
void loadTime(u8 number1,u8 number2,u8 number3);
//mergeLED,24位segmentLED
u32 mergeLED(u8 ledBus0,u8 ledBus1,u8 ledSel);
#endif

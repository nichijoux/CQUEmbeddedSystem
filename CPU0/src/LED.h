#ifndef _LED_H_
#define _LED_H_

#include "xplatform_info.h"
#include "zhmacro.h"
#include "KEYS.h"

//led�豸
#define LEDS_DEVICE_ID XPAR_GPIO_LEDS_DEVICE_ID

#define RED_LED_CHANNEL CHANNEL1
#define SEG_LED_CHANNEL CHANNEL2

#define LED_SHOW_TIME	1
#define LED_SHOW_YEAR	2

//LED_DELAY
#define LED_DELAY 			100000
#define LED_TIMER_VALUE		0x14585

//���ڻص������Ľṹ
typedef struct gpioLEDAndTimer{
	XScuTimer* timer;
	XGpio* gpioLED;
}gpioLEDAndTimer;

//��.c�г�ʼ��
//�߶������0~E
extern const u8 segmentsCode[];
//displayBuffer,�����߶�����ܵ���ʾbuffer
extern volatile u8 displayBuffer[];
//��ǰ������ʾ��һ������
extern volatile u8 displayIndex;
//������˸��λ��
extern volatile u8 twinkleIndex[2];
//Ҫ��˸��λ�ü���
extern volatile u32 twinkleCount;

//LED API

//GPIO��ʼ��
int initLEDDevice(XGpio* gpioLED);
//�жϺ���ע��
int setupLEDInterrupt(XScuGic* gic,gpioLEDAndTimer* ledAndTimer);
//��ʱ��ʾ�߶�����ܵĶ�ʱ������
void ledInterruptHandler(void* callbackRef);
//����displayBuffer
void loadTime(u8 number1,u8 number2,u8 number3);
//mergeLED,24λsegmentLED
u32 mergeLED(u8 ledBus0,u8 ledBus1,u8 ledSel);
#endif

#ifndef _ZHMACRO_H_
#define _ZHMACRO_H_

#include "xparameters.h"
#include "xscutimer.h"
#include "xscugic.h"
#include "xgpio.h"
#include "GicAndTimer.h"

//唤醒CPU1的宏
#define sev() 				__asm__("sev")
#define CPU1_START_UP_REG	0xFFFFFFF0U
#define CPU1_START_ADDRRESS	0x20000000U

//ICDSGIR SGI触发寄存器地址
#define ICDSGIR             0xF8F01F00
#define ICDIPTR             0xF8F01800

//CPU0和CPU1通信的OCM地址
#define OCMBuffer			((volatile u8*)0xFFFF0000U)
//OCMBuffer数组的OCMBuffer[0]为CPU1是否被中断
#define INTERRUPT_CPU1		0
//OCMBuffer数组的OCMBuffer[1]为闹钟选择的什么音乐
#define CLOCK_MUSIC			1
//OCMBuffer数组的OCMBuffer[2]为是否正在播放闹钟
#define IS_CLOCK_PLAY		2

#ifndef ZHCPU0ID
#define ZHCPU0ID
	#define CPU0_ID 0
	#define CPU1_ID 1
#endif

//私有定时器频率,计数频率同时也是1s的周期数
#ifndef ZHTIMERFRQ
#define ZHTIMERFRQ
	#define TIMER_FRQ 333333333
#endif

#ifndef DELAYFUNCTION
#define DELAYFUNCTION
	//delay宏函数
	#define delay(number) for(int i = 0;i < number;i++);
#endif

#ifndef CHANNELNUMBER
#define CHANNELNUMBER
	//GPIO通道
	#define CHANNEL1 1
	#define CHANNEL2 2
#endif

#ifndef ZHTRUEFALSE
#define ZHTRUEFALSE
	#define true 1
	#define false 0
#endif

#ifndef ZHPRINT
#define ZHPRINT
	#define print xil_printf
#endif
#endif

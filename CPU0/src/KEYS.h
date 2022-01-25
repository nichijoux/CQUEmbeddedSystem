#ifndef _KEYS_H_
#define _KEYS_H_

#include "xparameters.h"
#include "xscutimer.h"
#include "xscugic.h"
#include "xgpio.h"
#include "zhmacro.h"
#include "LED.h"
#include "DS1302.h"

//GPIO CHANNEL
#define MT_CHANNEL CHANNEL1
#define SP_CHANNEL CHANNEL2

//矩阵键盘的延时
#define KEYS_DELAY_TIME 		166666
//矩阵键盘设备ID
#define KEYS_DEVICE_ID 			XPAR_GPIO_KEYS_DEVICE_ID
//矩阵键盘中断ID
#define KEYS_INTERRUPT_ID		XPAR_FABRIC_GPIO_KEYS_IP2INTC_IRPT_INTR
//矩阵键盘中断掩码
#define KEYS_INTERRUPT_MASK		0xFFFFFFFF

//判断矩阵键盘是否被中断
volatile u8 interruptKeysFlag;
//矩阵键盘
volatile u8 readKeysMT;
//独立按键
volatile u8 readKeysSP;
//是否显示时间
volatile u8 isShowTime;
//是否显示学号
volatile u8 isShowID;
//当前显示的是第几个闹钟
volatile u8 clockID;
//设定闹钟所需的hour、minute、second
volatile u8 clockHour;
volatile u8 clockMinute;
volatile u8 clockSecond;
volatile u8 clockMusic;
//设定时间的hour、minute、second
volatile u8 setHour;
volatile u8 setMinute;
volatile u8 setSecond;
//设定时间的year、month、date
volatile u8 setYear;
volatile u8 setMonth;
volatile u8 setDate;
//是否正在debug模式
volatile u8 isDebug;
//是否正在设置闹钟
volatile u8 isShowClock;
//是否正在预览音乐
volatile u8 isPreviewSong;

//API
//键盘GPIO初始化
int initKeysDevice(XGpio* gpioKEYS);
//注册键盘中断
int setupKEYSInterrupt(XGpio* gpioKEYS,XScuGic* gic);
//读取矩阵键盘
int readKeys(XGpio* gpioKEYS,XScuGic* gic);
//处理键盘事件
int solveKeysEvent(XGpio* gpioKEYS,int eventID,XGpio* gpioDS1302,XScuGic* gic);
//扫描矩阵键盘
int scanMTKeys(XGpio* gpioKEYS);
//扫描独立按键
int scanSPKeys(XGpio* gpioKEYS);
//中断处理函数
void keysHandler(void* callbackRef);

//键盘的宏定义
#define KEY_SUB 		4
#define KEY_ADD			5
#define KEY_SHOWTIME	6
#define KEY_SHOWID		7
//上下位置
#define KEY_PREV		8
#define KEY_NEXT		9
//播放(暂停预览音乐)
#define	KEY_PREVIEWSONG	10
//进入设置模式
#define KEY_SETTIME		11
//确认,取消
#define KEY_ENSURE		12
#define KEY_CANCEL		13
//切换音乐(序号)
#define KEY_PREVSONG	14
#define KEY_NEXTSONG	15
//可设定4个闹钟(在设定模式下为设定闹钟,其余模式下为显示设定的闹钟)
#define KEY_CLOCK1		16
#define KEY_CLOCK2		17
#define KEY_CLOCK3		18
#define KEY_CLOCK4		19
//独立按键的宏
//切换音乐
#define KEY_MUSIC1		0
#define KEY_MUSIC2		1
#define KEY_MUSIC3		2
#define KEY_MUSIC4		3
//键盘按下的音乐
#define PLAY_MUISCKEY	4

#endif

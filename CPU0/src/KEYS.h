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

//������̵���ʱ
#define KEYS_DELAY_TIME 		166666
//��������豸ID
#define KEYS_DEVICE_ID 			XPAR_GPIO_KEYS_DEVICE_ID
//��������ж�ID
#define KEYS_INTERRUPT_ID		XPAR_FABRIC_GPIO_KEYS_IP2INTC_IRPT_INTR
//��������ж�����
#define KEYS_INTERRUPT_MASK		0xFFFFFFFF

//�жϾ�������Ƿ��ж�
volatile u8 interruptKeysFlag;
//�������
volatile u8 readKeysMT;
//��������
volatile u8 readKeysSP;
//�Ƿ���ʾʱ��
volatile u8 isShowTime;
//�Ƿ���ʾѧ��
volatile u8 isShowID;
//��ǰ��ʾ���ǵڼ�������
volatile u8 clockID;
//�趨���������hour��minute��second
volatile u8 clockHour;
volatile u8 clockMinute;
volatile u8 clockSecond;
volatile u8 clockMusic;
//�趨ʱ���hour��minute��second
volatile u8 setHour;
volatile u8 setMinute;
volatile u8 setSecond;
//�趨ʱ���year��month��date
volatile u8 setYear;
volatile u8 setMonth;
volatile u8 setDate;
//�Ƿ�����debugģʽ
volatile u8 isDebug;
//�Ƿ�������������
volatile u8 isShowClock;
//�Ƿ�����Ԥ������
volatile u8 isPreviewSong;

//API
//����GPIO��ʼ��
int initKeysDevice(XGpio* gpioKEYS);
//ע������ж�
int setupKEYSInterrupt(XGpio* gpioKEYS,XScuGic* gic);
//��ȡ�������
int readKeys(XGpio* gpioKEYS,XScuGic* gic);
//��������¼�
int solveKeysEvent(XGpio* gpioKEYS,int eventID,XGpio* gpioDS1302,XScuGic* gic);
//ɨ��������
int scanMTKeys(XGpio* gpioKEYS);
//ɨ���������
int scanSPKeys(XGpio* gpioKEYS);
//�жϴ�����
void keysHandler(void* callbackRef);

//���̵ĺ궨��
#define KEY_SUB 		4
#define KEY_ADD			5
#define KEY_SHOWTIME	6
#define KEY_SHOWID		7
//����λ��
#define KEY_PREV		8
#define KEY_NEXT		9
//����(��ͣԤ������)
#define	KEY_PREVIEWSONG	10
//��������ģʽ
#define KEY_SETTIME		11
//ȷ��,ȡ��
#define KEY_ENSURE		12
#define KEY_CANCEL		13
//�л�����(���)
#define KEY_PREVSONG	14
#define KEY_NEXTSONG	15
//���趨4������(���趨ģʽ��Ϊ�趨����,����ģʽ��Ϊ��ʾ�趨������)
#define KEY_CLOCK1		16
#define KEY_CLOCK2		17
#define KEY_CLOCK3		18
#define KEY_CLOCK4		19
//���������ĺ�
//�л�����
#define KEY_MUSIC1		0
#define KEY_MUSIC2		1
#define KEY_MUSIC3		2
#define KEY_MUSIC4		3
//���̰��µ�����
#define PLAY_MUISCKEY	4

#endif

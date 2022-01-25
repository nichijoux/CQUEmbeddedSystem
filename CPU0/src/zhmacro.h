#ifndef _ZHMACRO_H_
#define _ZHMACRO_H_

#include "xparameters.h"
#include "xscutimer.h"
#include "xscugic.h"
#include "xgpio.h"
#include "GicAndTimer.h"

//����CPU1�ĺ�
#define sev() 				__asm__("sev")
#define CPU1_START_UP_REG	0xFFFFFFF0U
#define CPU1_START_ADDRRESS	0x20000000U

//ICDSGIR SGI�����Ĵ�����ַ
#define ICDSGIR             0xF8F01F00
#define ICDIPTR             0xF8F01800

//CPU0��CPU1ͨ�ŵ�OCM��ַ
#define OCMBuffer			((volatile u8*)0xFFFF0000U)
//OCMBuffer�����OCMBuffer[0]ΪCPU1�Ƿ��ж�
#define INTERRUPT_CPU1		0
//OCMBuffer�����OCMBuffer[1]Ϊ����ѡ���ʲô����
#define CLOCK_MUSIC			1
//OCMBuffer�����OCMBuffer[2]Ϊ�Ƿ����ڲ�������
#define IS_CLOCK_PLAY		2

#ifndef ZHCPU0ID
#define ZHCPU0ID
	#define CPU0_ID 0
	#define CPU1_ID 1
#endif

//˽�ж�ʱ��Ƶ��,����Ƶ��ͬʱҲ��1s��������
#ifndef ZHTIMERFRQ
#define ZHTIMERFRQ
	#define TIMER_FRQ 333333333
#endif

#ifndef DELAYFUNCTION
#define DELAYFUNCTION
	//delay�꺯��
	#define delay(number) for(int i = 0;i < number;i++);
#endif

#ifndef CHANNELNUMBER
#define CHANNELNUMBER
	//GPIOͨ��
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

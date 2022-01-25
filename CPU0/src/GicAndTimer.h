#ifndef _TIMER_H_
#define _TIMER_H_
#include "zhmacro.h"

//PPI
//GIC��ID
#define GIC_DEVICE_ID 				XPAR_SCUGIC_SINGLE_DEVICE_ID
//˽�ж�ʱ����ID
#define PRIVATE_TIMER_DEVICE_ID		XPAR_XSCUTIMER_0_DEVICE_ID
//˽�ж�ʱ���ж�
#define PRIVATE_TIMER_INTERRUPT_ID	XPAR_SCUTIMER_INTR

//��ʼ��GIC�豸
int initScuGicDevice(XScuGic* gic);
//�쳣����ע��
void initScuGicException(XScuGic* gic);
//��ʼ��˽��Timer
int initPrivateTimerDevice(XScuTimer* timer);

//��������ж�SGI
//��������жϺ�
#define SGI0_ID    0
#define SGI1_ID    1
#define SGI2_ID    2
#define SGI3_ID    3
#define SGI4_ID    4
#define SGI5_ID    5
#define SGI6_ID    6
#define SGI7_ID    7
#define SGI8_ID    8
#define SGI9_ID    9
#define SGI10_ID   10
#define SGI11_ID   11
#define SGI12_ID   12
#define SGI13_ID   13
#define SGI14_ID   14
#define SGI15_ID   15

//ע��SGI
int setupSGIInterrupt(XScuGic* gic,u8 SGI_ID,Xil_ExceptionHandler handler,
		void* argument,u8 targetCpuID);
#endif

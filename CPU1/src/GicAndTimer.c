#include "GicAndTimer.h"

//��ʼ��GIC
int initScuGicDevice(XScuGic* gic){
	int status = XST_SUCCESS;
	//GIC���ýṹ
	XScuGic_Config* gicConfig = NULL;
	gicConfig = XScuGic_LookupConfig(GIC_DEVICE_ID);
	if(gicConfig == NULL){
		return XST_FAILURE;
	}
	//��ʼ��GIC
	status = XScuGic_CfgInitialize(gic,gicConfig,gicConfig->CpuBaseAddress);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

//�쳣����ע��
void initScuGicException(XScuGic* gic){
	//�ж��쳣ע��
	Xil_ExceptionInit();
	//�жϷ������쳣ע��
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
			(Xil_ExceptionHandler)XScuGic_InterruptHandler,
			gic);
	//�����쳣����
	Xil_ExceptionEnable();
}

//��ʼ��˽�ж�ʱ��
int initPrivateTimerDevice(XScuTimer* timer){
	int status = XST_SUCCESS;
	XScuTimer_Config* timerConfig = NULL;
	timerConfig = XScuTimer_LookupConfig(PRIVATE_TIMER_DEVICE_ID);
	if(timerConfig == NULL){
		return XST_FAILURE;
	}
	//��ʼ��Timer
	status = XScuTimer_CfgInitialize(timer,timerConfig,timerConfig->BaseAddr);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//Timer�Բ�
	status = XScuTimer_SelfTest(timer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

//ע��SGI
int setupSGIInterrupt(XScuGic* gic,u8 SGI_ID,Xil_ExceptionHandler handler,
		void* argument,u8 targetCpuID){

	XScuGic_SetPriorityTriggerType(gic,SGI_ID,0xD0,0x3);
	int status = XScuGic_Connect(gic,SGI_ID,handler,argument);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	XScuGic_Enable(gic,SGI_ID);
	XScuGic_InterruptMaptoCpu(gic,targetCpuID,SGI_ID);
	return status;
}

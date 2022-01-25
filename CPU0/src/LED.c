#include "LED.h"

//�߶������0~E
const u8 segmentsCode[16] = {
		0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
		0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71
};

//displayBuffer,�����߶�����ܵ���ʾbuffer
volatile u8 displayBuffer[8] = {
		0X3F,0X3F,0X40,0X3F,0X3F,0X40,0X3F,0X3
};

//displayIndex,��ǰ������ʾ�ڼ�������
volatile u8 displayIndex = 0;
//����ʾ��λ��(bit1 Ϊ����ʾ,bit0 Ϊ�ر�)
volatile u8 viewIndex = 0xFF;
//������˸��λ��(Ĭ�������������λ)
volatile u8 twinkleIndex[2] = {
		6,7
};
//Ҫ��˸��λ�ü���
volatile u32 twinkleCount = 0;

//��ʼ��GPIO�豸
int initLEDDevice(XGpio* gpioLED){
	int status = XST_SUCCESS;
	status = XGpio_Initialize(gpioLED,LEDS_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//����GPIOLED�ķ���
	XGpio_SetDataDirection(gpioLED,RED_LED_CHANNEL,0);
	XGpio_SetDataDirection(gpioLED,SEG_LED_CHANNEL,0);
	return XST_SUCCESS;
}

//�жϺ���ע��
int setupLEDInterrupt(XScuGic* gic,gpioLEDAndTimer* ledAndTimer){
	int status = XST_SUCCESS;
	XScuTimer* timer = ledAndTimer->timer;
	//timer�ж�
	status = XScuGic_Connect(gic,PRIVATE_TIMER_INTERRUPT_ID,
			(Xil_ExceptionHandler)ledInterruptHandler,
			ledAndTimer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//����˽�ж�ʱ��(29��)�ж�
	XScuGic_Enable(gic,PRIVATE_TIMER_INTERRUPT_ID);
	XScuTimer_EnableInterrupt(timer);
	//����˽�ж�ʱ���Զ���װ
	XScuTimer_EnableAutoReload(timer);
	//���ؼĴ���
	XScuTimer_LoadTimer(timer,LED_TIMER_VALUE);
	//��ʼtimer
	XScuTimer_Start(timer);
	return status;
}

//��ʱ��ʾ�߶�����ܵĶ�ʱ��������
void ledInterruptHandler(void* callbackRef){
	gpioLEDAndTimer* ledAndTimer = (gpioLEDAndTimer*)callbackRef;
	XGpio* gpioLED = ledAndTimer->gpioLED;
	XScuTimer* timer = ledAndTimer->timer;
	//�����ʱ������
	if(XScuTimer_IsExpired(timer)){
		//����ж�״̬
		XScuTimer_ClearInterruptStatus(timer);
		displayIndex = (displayIndex + 1) % 8;
		u8 ledBUS0 = displayIndex < 4 ? displayBuffer[displayIndex] : 0;
		u8 ledBUS1 = displayIndex >= 4 ? displayBuffer[displayIndex] : 0;
		//һ��ֻ��ʾ1λ
		u8 ledSel = ~(0xFF & (1 << displayIndex));
		if(isDebug &&
					(displayIndex == twinkleIndex[0] ||
								displayIndex == twinkleIndex[1])){
			twinkleCount = (twinkleCount + 1) % 600;
			if(twinkleCount < 300){
				XGpio_DiscreteWrite(gpioLED,SEG_LED_CHANNEL,
						mergeLED(ledBUS0,ledBUS1,ledSel));
			}else{
				//���
				XGpio_DiscreteWrite(gpioLED,SEG_LED_CHANNEL,
						mergeLED(ledBUS0,ledBUS1,0xFF));
			}
		}else{
			XGpio_DiscreteWrite(gpioLED,SEG_LED_CHANNEL,
					mergeLED(ledBUS0,ledBUS1,ledSel));
		}
	}
}

//����displayBuffer
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

//mergeLED,24λsegmentLED
inline u32 mergeLED(u8 ledBus0,u8 ledBus1,u8 ledSel){
	return (((u32)ledBus0) + ((u32)ledBus1 << 8) + ((u32)ledSel << 16));
}

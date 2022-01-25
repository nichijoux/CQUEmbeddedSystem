#include "KEYS.h"

//�жϾ�������Ƿ��ж�
volatile u8 interruptKeysFlag = 0;
volatile u8 readKeysMT = 0x0F;
volatile u8 readKeysSP = 0x0F;
//�Ƿ���ʾʱ��(Ĭ����ʾ,1Ϊ��ʾʱ��,2Ϊ��ʾ������)
volatile u8 isShowTime = LED_SHOW_TIME;
//�Ƿ���ʾѧ��(Ĭ�ϲ���ʾ)
volatile u8 isShowID = false;
//��ǰ�����趨�ڼ�������
volatile u8 clockID = 0;
//�趨���������hour��minute��second
volatile u8 clockHour = 0;
volatile u8 clockMinute = 0;
volatile u8 clockSecond = 0;
volatile u8 clockMusic = 0;
//�趨ʱ���hour��minute��second
volatile u8 setHour = 0;
volatile u8 setMinute = 0;
volatile u8 setSecond = 0;
//�趨ʱ���year��month��date
volatile u8 setYear = 0;
volatile u8 setMonth = 0;
volatile u8 setDate = 0;
//�Ƿ�����debugģʽ
volatile u8 isDebug = false;
//�Ƿ�������������
volatile u8 isShowClock = false;
//�Ƿ�����Ԥ������
volatile u8 isPreviewSong = false;

//��ʼ������GPIO
int initKeysDevice(XGpio* gpioKEYS){
	int status = 0;
	status = XGpio_Initialize(gpioKEYS,KEYS_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//���þ�����̵ķ���(����λ���,����λ����)
	XGpio_SetDataDirection(gpioKEYS,MT_CHANNEL,0x0F);
	//���ö��������ķ���(ȫΪ����)
	XGpio_SetDataDirection(gpioKEYS,SP_CHANNEL,0x0F);
	//�ڸ���λ���0,����λ���1
	XGpio_DiscreteWrite(gpioKEYS,MT_CHANNEL,0x0F);
	return XST_SUCCESS;
}

//ע������ж�
int setupKEYSInterrupt(XGpio* gpioKEYS,XScuGic* gic){
	int status = XST_SUCCESS;

	//�����ж����ȼ�,���һ������Ϊ������ʽ,0x03->0b11��Rising edge sensitive(�����ش���)
	XScuGic_SetPriorityTriggerType(gic,KEYS_INTERRUPT_ID,0xA0,0x03);
	//�����жϺ���
	status = XScuGic_Connect(gic,KEYS_INTERRUPT_ID,
			(Xil_ExceptionHandler)keysHandler,gpioKEYS);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//GIC�����ж�KEYS_INTERRUPT_ID(61)���ж�
	XScuGic_Enable(gic,KEYS_INTERRUPT_ID);
	//����KEYS_INTERRUPT_ID�ж�Ӧ�ô��͸�CPU0
	XScuGic_InterruptMaptoCpu(gic,CPU0_ID,KEYS_INTERRUPT_ID);
	//��������ж�
	XGpio_InterruptEnable(gpioKEYS,0x0F);
	//����ȫ���ж�
	XGpio_InterruptGlobalEnable(gpioKEYS);
	return XST_SUCCESS;
}

//��ȡ�������
int readKeys(XGpio* gpioKEYS,XScuGic* gic){
	int keyValue = -1;
	//������ж���ʼ
	if(interruptKeysFlag != 0){
		//���ż�����
		OCMBuffer[CLOCK_MUSIC] = PLAY_MUISCKEY;
		OCMBuffer[INTERRUPT_CPU1] = 1;
		XScuGic_SoftwareIntr(gic,SGI0_ID,0x1 << CPU1_ID);
		//ֱ�����������������
		while(OCMBuffer[IS_CLOCK_PLAY]);
		//��ʱ����
		delay(KEYS_DELAY_TIME);
		switch(interruptKeysFlag)
		{
		case 1:
			keyValue = scanSPKeys(gpioKEYS);
			break;
		case 2:
			keyValue = scanMTKeys(gpioKEYS);
			break;
		default:
			break;
		}
		if(keyValue != KEY_PREVSONG
				&& keyValue != KEY_NEXTSONG
				&& keyValue != KEY_PREVIEWSONG
				&& OCMBuffer[IS_CLOCK_PLAY]){
			OCMBuffer[INTERRUPT_CPU1] = 1;
		}
		//�����жϱ�ʶ
		interruptKeysFlag = 0;

		//����жϱ�ʶ
		XGpio_InterruptClear(gpioKEYS,KEYS_INTERRUPT_MASK);
		//���������ж�
		XGpio_InterruptGlobalEnable(gpioKEYS);
	}
	return keyValue;
}

//��������¼�
int solveKeysEvent(XGpio* gpioKEYS,int eventID,XGpio* gpioDS1302,XScuGic* gic){
	if(eventID != 1){
		switch(eventID)
		{
		//׼����������ģʽ
		case KEY_SETTIME:
		{
			if(isShowID || (isPreviewSong & 0x01)) break;
			isDebug = true;
			if(isShowTime == LED_SHOW_TIME){
				setHour = readDS1302Byte(gpioDS1302,DS1302_HOUR);
				setHour &= HOUR_MASK;
				setMinute = readDS1302Byte(gpioDS1302,DS1302_MINUTE);
				setMinute &= MINUTE_MASK;
				setSecond = readDS1302Byte(gpioDS1302,DS1302_SECOND);
				setSecond &= SECOND_MASK;
			}else if(isShowTime == LED_SHOW_YEAR){
				setYear = readDS1302Byte(gpioDS1302,DS1302_YEAR);
				setYear &= YEAR_MASK;
				setMonth = readDS1302Byte(gpioDS1302,DS1302_MONTH);
				setMonth &= MONTH_MASK;
				setDate = readDS1302Byte(gpioDS1302,DS1302_DATE);
				setDate &= DATE_MASK;
			}
			break;
		}
		//ȷ��
		case KEY_ENSURE:
		{
			if(isShowClock && isDebug){
				//��������
				//����ʱ��
				setClockHour[clockID] = clockHour;
				setClockMinute[clockID] = clockMinute;
				setClockSecond[clockID] = clockSecond;
				setClockMusic[clockID] = clockMusic;

				//����д����
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
				//д�������趨
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(clockID),setClockHour[clockID]);
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_MINUTE(clockID),setClockMinute[clockID]);
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_SECOND(clockID),setClockSecond[clockID]);
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_CLOCKMUSIC(clockID),setClockMusic[clockID]);
				//д��д����
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
			}else if(isShowTime == LED_SHOW_TIME && isDebug){
				//����д����
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
				//д�������趨
				writeDS1302Byte(gpioDS1302,DS1302_HOUR,setHour);
				writeDS1302Byte(gpioDS1302,DS1302_MINUTE,setMinute);
				writeDS1302Byte(gpioDS1302,DS1302_SECOND,setSecond);
				//д��д����
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
			}else if(isShowTime == LED_SHOW_YEAR && isDebug){
				//����д����
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
				//д�������趨
				writeDS1302Byte(gpioDS1302,DS1302_YEAR,setYear);
				writeDS1302Byte(gpioDS1302,DS1302_MONTH,setMonth);
				writeDS1302Byte(gpioDS1302,DS1302_DATE,setDate);
				//д��д����
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
			}
			isDebug = false;
			isShowClock = false;
			isPreviewSong = isPreviewSong & 0xFE;
			isShowTime = LED_SHOW_TIME;
			isShowID = false;
			break;
		}
		//ȡ��
		case KEY_CANCEL:
		{
			isDebug = false;
			isShowClock = false;
			isPreviewSong = isPreviewSong & 0xFE;
			isShowTime = LED_SHOW_TIME;
			isShowID = false;
			break;
		}
		//showTime
		case KEY_SHOWTIME:
		{
			isDebug = false;
			isShowID = false;
			isShowClock = false;
			isPreviewSong = isPreviewSong & 0xFE;
			if(isShowTime == LED_SHOW_TIME){
				isShowTime = LED_SHOW_YEAR;
			}else{
				isShowTime = LED_SHOW_TIME;
			}
			break;
		}
		//showID
		case KEY_SHOWID:
		{
			isDebug = false;
			isShowID = true;
			isShowTime = false;
			isShowClock = false;
			isPreviewSong = isPreviewSong & 0xFE;
			break;
		}
		//��һ��λ��
		case KEY_PREV:
		{
			if(isDebug && !isShowID){
				twinkleIndex[0] = (twinkleIndex[0] + 6) % 9;
				twinkleIndex[1] = twinkleIndex[0] + 1;
			}
			break;
		}
		//��һ��λ��
		case KEY_NEXT:
		{
			if(isDebug && !isShowID){
				twinkleIndex[0] = (twinkleIndex[0] + 3) % 9;
				twinkleIndex[1] = twinkleIndex[0] + 1;
			}
			break;
		}
		//Ԥ������
		case KEY_PREVIEWSONG:
		{
			isDebug = false;
			isShowClock = false;
			if(isPreviewSong & 0x01){
				//������ڲ�������
				isPreviewSong &= 0xFE;
				//֪ͨCPU1�ر�����
				//���Ʋ�������
				OCMBuffer[INTERRUPT_CPU1] = 2;
				isShowTime = LED_SHOW_TIME;
			}else{
				//���û��������
				isPreviewSong |= 0x01;
				//�ж�֪ͨ����;
				u8 songID = (isPreviewSong & 0xF0) >> 4;
				OCMBuffer[CLOCK_MUSIC] = songID;
				OCMBuffer[INTERRUPT_CPU1] = 1;

				loadTime(0,0,(isPreviewSong & 0xF0) >> 4);
				displayBuffer[2] = segmentsCode[0];
				displayBuffer[5] = segmentsCode[0];
				isShowTime = false;
			}
			break;
		}
		//Ԥ����һ�׸�
		case KEY_PREVSONG:
		{
			if(isPreviewSong & 0x01){
				u8 songID = (isPreviewSong & 0xF0) >> 4;
				songID = (songID + 3) % 4;
				isPreviewSong = (isPreviewSong & 0x0F) | (songID << 4);
				OCMBuffer[CLOCK_MUSIC] = songID;
				OCMBuffer[INTERRUPT_CPU1] = 1;
				//�л�����
				displayBuffer[7] = segmentsCode[songID];
			}
			break;
		}
		//Ԥ����һ�׸�
		case KEY_NEXTSONG:
		{
			if(isPreviewSong & 0x01){
				u8 songID = (isPreviewSong & 0xF0) >> 4;
				songID = (songID + 1) % 4;
				isPreviewSong = (isPreviewSong & 0x0F) | (songID << 4);
				OCMBuffer[CLOCK_MUSIC] = songID;
				OCMBuffer[INTERRUPT_CPU1] = 1;
				XScuGic_SoftwareIntr(gic,SGI0_ID,0x1 << CPU1_ID);
				//�л�����
				displayBuffer[7] = segmentsCode[songID];
			}
			break;
		}
		//��
		case KEY_ADD:
		{
			if(!isDebug) break;
			if(isShowClock){
				//��������
				if(twinkleIndex[0] == 6){
					//second
					clockSecond = (BCDToDEC(clockSecond) + 1) % 60;
					clockSecond = DECToBCD(clockSecond);
				}else if(twinkleIndex[0] == 3){
					//minute
					clockMinute = (BCDToDEC(clockMinute) + 1) % 60;
					clockMinute = DECToBCD(clockMinute);
				}else if(twinkleIndex[0] == 0){
					//hour
					clockHour = (BCDToDEC(clockHour) + 1) % 24;
					clockHour = DECToBCD(clockHour);
				}
				loadTime(clockHour,clockMinute,clockSecond);
			}else if(isShowTime == LED_SHOW_TIME && isDebug){
				//ʱ������
				if(twinkleIndex[0] == 6){
					//second
					setSecond = BCDToDEC(setSecond);
					setSecond = (setSecond + 1) % 60;
					setSecond = DECToBCD(setSecond);
				}else if(twinkleIndex[0] == 3){
					setMinute = BCDToDEC(setMinute);
					//minute
					setMinute = (setMinute + 1) % 60;
					setMinute = DECToBCD(setMinute);
				}else if(twinkleIndex[0] == 0){
					//hour
					setHour = BCDToDEC(setHour);
					setHour = (setHour + 1) % 24;
					setHour = DECToBCD(setHour);
				}
				loadTime(setHour,setMinute,setSecond);
			}else if(isShowTime == LED_SHOW_YEAR && isDebug){
				setYear = BCDToDEC(setYear);
				setMonth = BCDToDEC(setMonth);
				setDate = BCDToDEC(setDate);
				if(twinkleIndex[0] == 0){
					setYear = (setYear + 1) % 100;
				}else if(twinkleIndex[0] == 3){
					setMonth = setMonth % 12 + 1;
				}else if(twinkleIndex[0] == 6){
					setDate = BCDToDEC(setDate);
					if(setMonth == 1 || setMonth == 3
							|| setMonth == 5 || setMonth == 7
							|| setMonth == 8 || setMonth == 10
							|| setMonth == 12){
						setDate = setDate + 1 > 31 ? 1 : setDate + 1;
					} else if(setMonth == 2) {
						if(BCDToDEC(setYear) % 4 == 0){
							setDate = setDate + 1 > 29 ? 1 : setDate + 1;
						}else{
							setDate = setDate + 1 > 28 ? 1 : setDate + 1;
						}
					} else {
						setDate = setDate + 1 > 30 ? 1 : setDate + 1;
					}
				}
				setYear = DECToBCD(setYear);
				setMonth = DECToBCD(setMonth);
				setDate = DECToBCD(setDate);
				loadTime(setYear,setMonth,setDate);
			}
			break;
		}
		//��
		case KEY_SUB:
		{
			if(!isDebug) break;
			if(isShowClock){
				//��������
				if(twinkleIndex[0] == 6){
					//second
					clockSecond = (BCDToDEC(clockSecond) + 59) % 60;
					clockSecond = DECToBCD(clockSecond);
				}else if(twinkleIndex[0] == 3){
					//minute
					clockMinute = (BCDToDEC(clockMinute) + 59) % 60;
					clockMinute = DECToBCD(clockMinute);
				}else if(twinkleIndex[0] == 0){
					//hour
					clockHour = (BCDToDEC(clockHour) + 23) % 24;
					clockHour = DECToBCD(clockHour);
				}
				loadTime(clockHour,clockMinute,clockSecond);
			}else if(isShowTime == LED_SHOW_TIME && isDebug){
				//ʱ������
				if(twinkleIndex[0] == 6){
					//second
					setSecond = BCDToDEC(setSecond);
					setSecond = (setSecond + 59) % 60;
					setSecond = DECToBCD(setSecond);
				}else if(twinkleIndex[0] == 3){
					//minute
					setMinute = BCDToDEC(setMinute);
					setMinute = (setMinute + 59) % 60;
					setMinute = DECToBCD(setMinute);
				}else if(twinkleIndex[0] == 0){
					//hour
					setHour = BCDToDEC(setHour);
					setHour = (setHour + 23) % 24;
					setHour = DECToBCD(setHour);
				}
				loadTime(setHour,setMinute,setSecond);
			}else if(isShowTime == LED_SHOW_YEAR && isDebug){
				setYear = BCDToDEC(setYear);
				setMonth = BCDToDEC(setMonth);
				setDate = BCDToDEC(setDate);
				if(twinkleIndex[0] == 0){
					setYear = (setYear + 99) % 100;
				}else if(twinkleIndex[0] == 3){
					setMonth = setMonth - 1 <= 0 ? 12 : setMonth - 1;
				}else if(twinkleIndex[0] == 6){
					if(setMonth == 1 || setMonth == 3
						|| setMonth == 5 || setMonth == 7
						|| setMonth == 8 || setMonth == 10
						|| setMonth == 12){
							setDate = setDate - 1 <= 0 ? 31 : setDate - 1;
					} else if(setMonth == 2){
						if(BCDToDEC(setYear) % 4 == 0){
							setDate = setDate - 1 <= 0 ? 29 : setDate - 1;
						}else{
							setDate = setDate - 1 <= 0 ? 28 : setDate - 1;
						}
					} else{
						setDate = setDate - 1 <= 0 ? 30 : setDate - 1;
					}
				}
				setYear = DECToBCD(setYear);
				setMonth = DECToBCD(setMonth);
				setDate = DECToBCD(setDate);
				loadTime(setYear,setMonth,setDate);
			}
			break;
		}
		//�趨����(������ʾ����)
		case KEY_CLOCK1:
		case KEY_CLOCK2:
		case KEY_CLOCK3:
		case KEY_CLOCK4:
		{
			clockID = eventID - KEY_CLOCK1;
			isShowClock = true;
			isPreviewSong = isPreviewSong & 0xFE;
			isShowTime = false;
			isShowID = false;
			//չʾ����
			clockHour = readDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(clockID));
			clockHour &= HOUR_MASK;
			clockMinute = readDS1302Byte(gpioDS1302,getDS1302_CLOCK_MINUTE(clockID));
			clockMinute &= MINUTE_MASK;
			clockSecond = readDS1302Byte(gpioDS1302,getDS1302_CLOCK_SECOND(clockID));
			clockSecond &= SECOND_MASK;
			print("%x\n\r",clockHour);
			loadTime(clockHour,clockMinute,clockSecond);
			break;
		}
		default:
		{
			if(KEY_MUSIC1 <= eventID && eventID <= KEY_MUSIC4){
				//ѡ��ʲô����
				clockMusic = eventID;
			}
			break;
		}
		}
	}
	return XST_SUCCESS;
}

//ɨ��������
int scanMTKeys(XGpio* gpioKEYS){
	print("press MT key\n\r");
	int ansKeys = -1;
	u8 mtData = XGpio_DiscreteRead(gpioKEYS, MT_CHANNEL) & 0x0F;
	if(mtData == readKeysMT){
		//�������������Ϊ����λ����,����λ���
		XGpio_SetDataDirection(gpioKEYS, MT_CHANNEL, 0xF0);
		//����λ���1,����λ���0
		XGpio_DiscreteWrite(gpioKEYS,MT_CHANNEL,0xF0);
		//�ٶ�ȡ��4λ
		mtData = XGpio_DiscreteRead(gpioKEYS,MT_CHANNEL) & 0xF0;
		//ͨ��readKeysMT���жϵ�4λ,Ȼ��ͨ��mtData�жϸ�4λ
		switch(readKeysMT & 0x0F)
		{
		case 0x0E:
			switch(mtData & 0xF0)
			{
			case 0xE0:
				ansKeys = KEY_SHOWID;
				break;
			case 0xD0:
				ansKeys = KEY_SHOWTIME;
				break;
			case 0xB0:
				ansKeys = KEY_ADD;
				break;
			case 0x70:
				ansKeys = KEY_SUB;
				break;
			default:
				break;
			}
			break;
		case 0x0D:
			switch(mtData & 0xF0)
			{
			case 0xE0:
				ansKeys = KEY_SETTIME;
				break;
			case 0xD0:
				ansKeys = KEY_PREVIEWSONG;
				break;
			case 0xB0:
				ansKeys = KEY_NEXT;
				break;
			case 0x70:
				ansKeys = KEY_PREV;
				break;
			default:
				break;
			}
			break;
		case 0x0B:
			switch(mtData & 0xF0)
			{
			case 0xE0:
				ansKeys = KEY_NEXTSONG;
				break;
			case 0xD0:
				ansKeys = KEY_PREVSONG;
				break;
			case 0xB0:
				ansKeys = KEY_CANCEL;
				break;
			case 0x70:
				ansKeys = KEY_ENSURE;
				break;
			default:
				break;
			}
			break;
		case 0x07:
			switch(mtData & 0xF0)
			{
			case 0xE0:
				ansKeys = KEY_CLOCK4;
				break;
			case 0xD0:
				ansKeys = KEY_CLOCK3;
				break;
			case 0xB0:
				ansKeys = KEY_CLOCK2;
				break;
			case 0x70:
				ansKeys = KEY_CLOCK1;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	//���þ�����̵ķ���(����λ���,����λ����)
	XGpio_SetDataDirection(gpioKEYS,MT_CHANNEL,0x0F);
	//�ڸ���λ���0,����λ���1
	XGpio_DiscreteWrite(gpioKEYS,MT_CHANNEL,0x0F);
	return ansKeys;
}

//ɨ���������
int scanSPKeys(XGpio* gpioKEYS){
	print("press SP key\n\r");
	u8 spData = XGpio_DiscreteRead(gpioKEYS, SP_CHANNEL) & 0x0F;
	int ansKeys = -1;
	//��������������˳������Ϊ
	//0x0E 0x07 0x0B 0x0D
	//��˰����˳��ֱ�ֵ0~3
	if(spData == readKeysSP){
		switch(readKeysSP & 0x0F)
		{
		case 0x0E:
		{
			ansKeys = KEY_MUSIC1;
			break;
		}
		case 0x07:
		{
			ansKeys = KEY_MUSIC2;
			break;
		}
		case 0x0B:
		{
			ansKeys = KEY_MUSIC3;
			break;
		}
		case 0x0D:
		{
			ansKeys = KEY_MUSIC4;
			break;
		}
		default:
			break;
		}
	}
	return ansKeys;
}

//�жϻص�����
void keysHandler(void* callbackRef){
	XGpio *gpioPtr = (XGpio*)callbackRef;
    //�Ȱ�GPIO�жϹر�
    XGpio_InterruptGlobalDisable(gpioPtr);
    //����GPIO��־λ
    XGpio_InterruptClear(gpioPtr, KEYS_INTERRUPT_MASK);
    //��ȡ�������
    //ɨ���������
    readKeysSP = XGpio_DiscreteRead(gpioPtr, SP_CHANNEL) & 0x0F;
    //ɨ��������
    readKeysMT = XGpio_DiscreteRead(gpioPtr, MT_CHANNEL) & 0x0F;
    //���Ƿ�ı���
    if ((readKeysSP & 0x0F) != 0x0F){
    	interruptKeysFlag = 1;
    } else if((readKeysMT & 0x0F) != 0x0F){
    	interruptKeysFlag = 2;
    } else {
    	interruptKeysFlag = 0;
        //�����ж�
        XGpio_InterruptGlobalEnable(gpioPtr);
    }
}

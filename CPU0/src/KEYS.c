#include "KEYS.h"

//判断矩阵键盘是否被中断
volatile u8 interruptKeysFlag = 0;
volatile u8 readKeysMT = 0x0F;
volatile u8 readKeysSP = 0x0F;
//是否显示时间(默认显示,1为显示时间,2为显示年月日)
volatile u8 isShowTime = LED_SHOW_TIME;
//是否显示学号(默认不显示)
volatile u8 isShowID = false;
//当前正在设定第几个闹钟
volatile u8 clockID = 0;
//设定闹钟所需的hour、minute、second
volatile u8 clockHour = 0;
volatile u8 clockMinute = 0;
volatile u8 clockSecond = 0;
volatile u8 clockMusic = 0;
//设定时间的hour、minute、second
volatile u8 setHour = 0;
volatile u8 setMinute = 0;
volatile u8 setSecond = 0;
//设定时间的year、month、date
volatile u8 setYear = 0;
volatile u8 setMonth = 0;
volatile u8 setDate = 0;
//是否正在debug模式
volatile u8 isDebug = false;
//是否正在设置闹钟
volatile u8 isShowClock = false;
//是否正在预览音乐
volatile u8 isPreviewSong = false;

//初始化键盘GPIO
int initKeysDevice(XGpio* gpioKEYS){
	int status = 0;
	status = XGpio_Initialize(gpioKEYS,KEYS_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//设置矩阵键盘的方向(高四位输出,低四位输入)
	XGpio_SetDataDirection(gpioKEYS,MT_CHANNEL,0x0F);
	//设置独立按键的方向(全为输入)
	XGpio_SetDataDirection(gpioKEYS,SP_CHANNEL,0x0F);
	//在高四位输出0,低四位输出1
	XGpio_DiscreteWrite(gpioKEYS,MT_CHANNEL,0x0F);
	return XST_SUCCESS;
}

//注册键盘中断
int setupKEYSInterrupt(XGpio* gpioKEYS,XScuGic* gic){
	int status = XST_SUCCESS;

	//设置中断优先级,最后一个参数为触发方式,0x03->0b11即Rising edge sensitive(上升沿触发)
	XScuGic_SetPriorityTriggerType(gic,KEYS_INTERRUPT_ID,0xA0,0x03);
	//链接中断函数
	status = XScuGic_Connect(gic,KEYS_INTERRUPT_ID,
			(Xil_ExceptionHandler)keysHandler,gpioKEYS);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//GIC允许中断KEYS_INTERRUPT_ID(61)号中断
	XScuGic_Enable(gic,KEYS_INTERRUPT_ID);
	//设置KEYS_INTERRUPT_ID中断应该传送给CPU0
	XScuGic_InterruptMaptoCpu(gic,CPU0_ID,KEYS_INTERRUPT_ID);
	//允许键盘中断
	XGpio_InterruptEnable(gpioKEYS,0x0F);
	//允许全局中断
	XGpio_InterruptGlobalEnable(gpioKEYS);
	return XST_SUCCESS;
}

//读取矩阵键盘
int readKeys(XGpio* gpioKEYS,XScuGic* gic){
	int keyValue = -1;
	//如果被中断则开始
	if(interruptKeysFlag != 0){
		//播放键盘声
		OCMBuffer[CLOCK_MUSIC] = PLAY_MUISCKEY;
		OCMBuffer[INTERRUPT_CPU1] = 1;
		XScuGic_SoftwareIntr(gic,SGI0_ID,0x1 << CPU1_ID);
		//直到键盘声被播放完毕
		while(OCMBuffer[IS_CLOCK_PLAY]);
		//延时防抖
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
		//重置中断标识
		interruptKeysFlag = 0;

		//清除中断标识
		XGpio_InterruptClear(gpioKEYS,KEYS_INTERRUPT_MASK);
		//重新允许中断
		XGpio_InterruptGlobalEnable(gpioKEYS);
	}
	return keyValue;
}

//处理键盘事件
int solveKeysEvent(XGpio* gpioKEYS,int eventID,XGpio* gpioDS1302,XScuGic* gic){
	if(eventID != 1){
		switch(eventID)
		{
		//准备进入设置模式
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
		//确认
		case KEY_ENSURE:
		{
			if(isShowClock && isDebug){
				//保存闹钟
				//更新时间
				setClockHour[clockID] = clockHour;
				setClockMinute[clockID] = clockMinute;
				setClockSecond[clockID] = clockSecond;
				setClockMusic[clockID] = clockMusic;

				//消除写保护
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
				//写入闹钟设定
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(clockID),setClockHour[clockID]);
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_MINUTE(clockID),setClockMinute[clockID]);
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_SECOND(clockID),setClockSecond[clockID]);
				writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_CLOCKMUSIC(clockID),setClockMusic[clockID]);
				//写入写保护
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
			}else if(isShowTime == LED_SHOW_TIME && isDebug){
				//消除写保护
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
				//写入闹钟设定
				writeDS1302Byte(gpioDS1302,DS1302_HOUR,setHour);
				writeDS1302Byte(gpioDS1302,DS1302_MINUTE,setMinute);
				writeDS1302Byte(gpioDS1302,DS1302_SECOND,setSecond);
				//写入写保护
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
			}else if(isShowTime == LED_SHOW_YEAR && isDebug){
				//消除写保护
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
				//写入闹钟设定
				writeDS1302Byte(gpioDS1302,DS1302_YEAR,setYear);
				writeDS1302Byte(gpioDS1302,DS1302_MONTH,setMonth);
				writeDS1302Byte(gpioDS1302,DS1302_DATE,setDate);
				//写入写保护
				writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
			}
			isDebug = false;
			isShowClock = false;
			isPreviewSong = isPreviewSong & 0xFE;
			isShowTime = LED_SHOW_TIME;
			isShowID = false;
			break;
		}
		//取消
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
		//上一个位置
		case KEY_PREV:
		{
			if(isDebug && !isShowID){
				twinkleIndex[0] = (twinkleIndex[0] + 6) % 9;
				twinkleIndex[1] = twinkleIndex[0] + 1;
			}
			break;
		}
		//下一个位置
		case KEY_NEXT:
		{
			if(isDebug && !isShowID){
				twinkleIndex[0] = (twinkleIndex[0] + 3) % 9;
				twinkleIndex[1] = twinkleIndex[0] + 1;
			}
			break;
		}
		//预览音乐
		case KEY_PREVIEWSONG:
		{
			isDebug = false;
			isShowClock = false;
			if(isPreviewSong & 0x01){
				//如果正在播放音乐
				isPreviewSong &= 0xFE;
				//通知CPU1关闭音乐
				//定制播放音乐
				OCMBuffer[INTERRUPT_CPU1] = 2;
				isShowTime = LED_SHOW_TIME;
			}else{
				//如果没播放音乐
				isPreviewSong |= 0x01;
				//中断通知播放;
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
		//预览上一首歌
		case KEY_PREVSONG:
		{
			if(isPreviewSong & 0x01){
				u8 songID = (isPreviewSong & 0xF0) >> 4;
				songID = (songID + 3) % 4;
				isPreviewSong = (isPreviewSong & 0x0F) | (songID << 4);
				OCMBuffer[CLOCK_MUSIC] = songID;
				OCMBuffer[INTERRUPT_CPU1] = 1;
				//切换音乐
				displayBuffer[7] = segmentsCode[songID];
			}
			break;
		}
		//预览下一首歌
		case KEY_NEXTSONG:
		{
			if(isPreviewSong & 0x01){
				u8 songID = (isPreviewSong & 0xF0) >> 4;
				songID = (songID + 1) % 4;
				isPreviewSong = (isPreviewSong & 0x0F) | (songID << 4);
				OCMBuffer[CLOCK_MUSIC] = songID;
				OCMBuffer[INTERRUPT_CPU1] = 1;
				XScuGic_SoftwareIntr(gic,SGI0_ID,0x1 << CPU1_ID);
				//切换音乐
				displayBuffer[7] = segmentsCode[songID];
			}
			break;
		}
		//加
		case KEY_ADD:
		{
			if(!isDebug) break;
			if(isShowClock){
				//闹钟设置
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
				//时间设置
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
		//减
		case KEY_SUB:
		{
			if(!isDebug) break;
			if(isShowClock){
				//闹钟设置
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
				//时间设置
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
		//设定闹钟(或者显示闹钟)
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
			//展示闹钟
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
				//选择什么音乐
				clockMusic = eventID;
			}
			break;
		}
		}
	}
	return XST_SUCCESS;
}

//扫描矩阵键盘
int scanMTKeys(XGpio* gpioKEYS){
	print("press MT key\n\r");
	int ansKeys = -1;
	u8 mtData = XGpio_DiscreteRead(gpioKEYS, MT_CHANNEL) & 0x0F;
	if(mtData == readKeysMT){
		//将矩阵键盘设置为高四位输入,低四位输出
		XGpio_SetDataDirection(gpioKEYS, MT_CHANNEL, 0xF0);
		//高四位输出1,低四位输出0
		XGpio_DiscreteWrite(gpioKEYS,MT_CHANNEL,0xF0);
		//再读取高4位
		mtData = XGpio_DiscreteRead(gpioKEYS,MT_CHANNEL) & 0xF0;
		//通过readKeysMT先判断低4位,然后通过mtData判断高4位
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
	//设置矩阵键盘的方向(高四位输出,低四位输入)
	XGpio_SetDataDirection(gpioKEYS,MT_CHANNEL,0x0F);
	//在高四位输出0,低四位输出1
	XGpio_DiscreteWrite(gpioKEYS,MT_CHANNEL,0x0F);
	return ansKeys;
}

//扫描独立按键
int scanSPKeys(XGpio* gpioKEYS){
	print("press SP key\n\r");
	u8 spData = XGpio_DiscreteRead(gpioKEYS, SP_CHANNEL) & 0x0F;
	int ansKeys = -1;
	//独立按键从左到右顺序依次为
	//0x0E 0x07 0x0B 0x0D
	//因此按这个顺序分别赋值0~3
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

//中断回调函数
void keysHandler(void* callbackRef){
	XGpio *gpioPtr = (XGpio*)callbackRef;
    //先把GPIO中断关闭
    XGpio_InterruptGlobalDisable(gpioPtr);
    //清理GPIO标志位
    XGpio_InterruptClear(gpioPtr, KEYS_INTERRUPT_MASK);
    //读取矩阵键盘
    //扫描独立键盘
    readKeysSP = XGpio_DiscreteRead(gpioPtr, SP_CHANNEL) & 0x0F;
    //扫描矩阵键盘
    readKeysMT = XGpio_DiscreteRead(gpioPtr, MT_CHANNEL) & 0x0F;
    //看是否改变了
    if ((readKeysSP & 0x0F) != 0x0F){
    	interruptKeysFlag = 1;
    } else if((readKeysMT & 0x0F) != 0x0F){
    	interruptKeysFlag = 2;
    } else {
    	interruptKeysFlag = 0;
        //允许中断
        XGpio_InterruptGlobalEnable(gpioPtr);
    }
}

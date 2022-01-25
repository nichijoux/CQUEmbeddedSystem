#include "MIDI.h"

//重装时间
u32 reloadTime = 0;
//音符演奏次数
u32 noteCount = 0;
//音符演奏次数
u32 noteIndex = 0;
//音乐高低电平
volatile u8 musicLevel = 0;
//当前播放哪一首歌
volatile u8 playSongIndex = 0;

//GPIO MIDI初始化
int initMIDIDevice(XGpio* gpioMIDI){
	int status = XST_SUCCESS;
	status = XGpio_Initialize(gpioMIDI,MIDI_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//设置方向为输出
	XGpio_SetDataDirection(gpioMIDI,MIDI_CHANNEL,0);
	//初始化歌曲列表
	initSongList();
	return XST_SUCCESS;
}

//计算音符所需重装时间
u32 calNoteReloadTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat)
{
	if(note != KEY_NOP){
		//乘5是因为原音符频率都乘以了10,而后需要除2得到0.5个周期的时间
		return TIMER_FRQ / note * 5 * dotted;
	}else{
		return TIMER_FRQ / beat / playSpeed * playBeat * 60 * dotted;
	}
}

//计算该音符的定时器中断次数，如果该音符为休止符则只中断一次
u32 calInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat){
	return calNoteReloadTime(0,beat,dotted,playSpeed,playBeat) / note;
}

//计算重置定时器中断次数,及定时器中断时间
void loadInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat){
	reloadTime = calNoteReloadTime(note,beat,dotted,playSpeed,playBeat);
	noteCount = calInterruptTime(reloadTime,beat,dotted,playSpeed,playBeat);
}

//播放音乐的中断函数
int setupMIDIInterrupt(XScuGic* gic,gpioMIDIAndTimer* midiAndTimer){
	XScuTimer* timer = midiAndTimer->timer;
	int status = XST_SUCCESS;
	//可能不是第一次注册,因此先disconnect
	//29号私有定时器中断
	status = XScuGic_Connect(gic, PRIVATE_TIMER_INTERRUPT_ID,
				(Xil_ExceptionHandler)midiInterruptHandler,
				midiAndTimer);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//允许29号中断
	XScuGic_Enable(gic,PRIVATE_TIMER_INTERRUPT_ID);
	//允许私有定时器自动重装
	XScuTimer_EnableAutoReload(timer);
	//允许timer向外发出中断信号
	XScuTimer_EnableInterrupt(timer);
	return XST_SUCCESS;
}

//音乐中断函数
void midiInterruptHandler(void* callbackRef){
	gpioMIDIAndTimer* midiAndTimer = (gpioMIDIAndTimer*)callbackRef;
	XGpio* gpioMIDI = midiAndTimer->gpioMIDI;
	XScuTimer* timer = midiAndTimer->timer;
	if(XScuTimer_IsExpired(timer)){
		//清除中断状态
		XScuTimer_ClearInterruptStatus(timer);
		noteCount--;
		musicLevel = ~musicLevel;
		//如果音符已经演奏完成
		if(noteCount == 0){
			noteIndex++;
			if(noteIndex >= songList[playSongIndex].songLength){
				//停止播放
				XScuTimer_Stop(timer);
				OCMBuffer[IS_CLOCK_PLAY] = false;
			}
			const MusicNote* song = songList[playSongIndex].realSong;
			loadInterruptTime(
					song[noteIndex].Note,
					song[noteIndex].Beat,
					song[noteIndex].Dotted,
					songList[playSongIndex].playSpeed,
					songList[playSongIndex].playBeat
			);
			XScuTimer_LoadTimer(timer,reloadTime);
			musicLevel = 0;
		}
		//输出扬声器电平
		XGpio_DiscreteWrite(gpioMIDI,MIDI_CHANNEL,musicLevel);
	}
}

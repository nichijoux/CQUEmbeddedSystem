#ifndef _MIDI_H_
#define _MIDI_H_

//曲谱头文件
#include "song.h"
#include "zhmacro.h"

//GPIO设备及宏定义
#define MIDI_DEVICE_ID		XPAR_GPIO_MIDI_DEVICE_ID
#define MIDI_CHANNEL		CHANNEL1

//重装时间
extern u32 reloadTime;
//音符演奏次数
extern u32 noteCount;
//音符index
extern u32 noteIndex;
//音乐高低电平
extern volatile u8 musicLevel;
//当前播放哪一首歌
extern volatile u8 playSongIndex;

typedef struct gpioMIDIAndTimer{
	XGpio* gpioMIDI;
	XScuTimer* timer;
}gpioMIDIAndTimer;

//GPIO MIDI初始化
int initMIDIDevice(XGpio* gpioMIDI);
//计算音符重装时间
u32 calNoteReloadTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat);
//计算该音符的定时器中断次数,如果该音符为休止符则只中断一次
u32 calInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat);
//计算重置定时器中断次数,及定时器中断时间
void loadInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat);
//播放音乐的中断函数
int setupMIDIInterrupt(XScuGic* gic,gpioMIDIAndTimer* midiAndTimer);
//音乐中断函数
void midiInterruptHandler(void* callbackRef);

#endif

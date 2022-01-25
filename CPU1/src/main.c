#include <stdio.h>
#include "MIDI.h"
#include "xil_mmu.h"

void SGIPlayClockMusic(void* callback);
void SGICloseMusic(void* callback);

int main(int argc,char** argv){
	//去除OCM的cache属性
	Xil_SetTlbAttributes(0xFFFF0000,0x14de2);
	XGpio gpioMIDI;
	int status = XST_SUCCESS;
	status = initMIDIDevice(&gpioMIDI);

	//GIC和私有定时器
	XScuGic gic;
	//初始化GIC(通用中断控制器)
	status = initScuGicDevice(&gic);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	XScuTimer timer;
	//初始化CPU1的私有定时器
	status = initPrivateTimerDevice(&timer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//中断函数参数传递
	gpioMIDIAndTimer midiAndTimer;
	midiAndTimer.gpioMIDI = &gpioMIDI;
	midiAndTimer.timer = &timer;

	//SGI注册

	//中断函数绑定
	status = setupMIDIInterrupt(&gic,&midiAndTimer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//异常注册
	initScuGicException(&gic);

	while(true){
		while(OCMBuffer[INTERRUPT_CPU1] == false);
		//播放音乐
		if(OCMBuffer[INTERRUPT_CPU1] == 1){
			OCMBuffer[INTERRUPT_CPU1] = false;
			//先关闭音乐
			XScuTimer_Stop(&timer);
			noteIndex = 0;
			playSongIndex = OCMBuffer[CLOCK_MUSIC];
			const MusicNote* song = songList[playSongIndex].realSong;
			loadInterruptTime(song[noteIndex].Note,
							song[noteIndex].Beat,
							song[noteIndex].Dotted,
							songList[playSongIndex].playSpeed,
							songList[playSongIndex].playBeat);
			XGpio_DiscreteWrite(&gpioMIDI,MIDI_CHANNEL,musicLevel);
			//加载数据
			XScuTimer_LoadTimer(&timer,reloadTime);
			//开始播放音乐
			print("start clock %d\n\r",OCMBuffer[CLOCK_MUSIC]);
			OCMBuffer[IS_CLOCK_PLAY] = true;
			XScuTimer_Start(&timer);
		}else if(OCMBuffer[INTERRUPT_CPU1] == 2){
			OCMBuffer[INTERRUPT_CPU1] = false;
			//关闭音乐
			noteIndex = 0;
			OCMBuffer[IS_CLOCK_PLAY] = false;
			XScuTimer_Stop(&timer);
		}
//		//重置flag,继续等待中断
//		OCMBuffer[INTERRUPT_CPU1] = false;
//		//正在播放则换音乐,否则关闭
//		if(OCMBuffer[NEED_MUSIC_PLAY] == false){
//			//先关闭音乐
//			OCMBuffer[IS_CLOCK_PLAY] = false;
//			print("close\n\r");
//			XScuTimer_Stop(&timer);
//		}else{
//			noteIndex = 0;
//			//被触发后播放音乐
//			playSongIndex = OCMBuffer[CLOCK_MUSIC];
//			const MusicNote* song = songList[playSongIndex].realSong;
//			loadInterruptTime(song[noteIndex].Note,
//					song[noteIndex].Beat,
//					song[noteIndex].Dotted,
//					songList[playSongIndex].playSpeed,
//					songList[playSongIndex].playBeat);
//			XGpio_DiscreteWrite(&gpioMIDI,MIDI_CHANNEL,musicLevel);
//			//加载数据
//			XScuTimer_LoadTimer(&timer,reloadTime);
//			//开始播放音乐
//			print("start clock %d\n\r",OCMBuffer[CLOCK_MUSIC]);
//			XScuTimer_Start(&timer);
//			if(OCMBuffer[CLOCK_MUSIC] != 4)
//				OCMBuffer[IS_CLOCK_PLAY] = true;
//		}
	}
	return XST_SUCCESS;
}

void SGIPlayClockMusic(void* callback){
	gpioMIDIAndTimer* midiAndTimer = (gpioMIDIAndTimer*)callback;
	XGpio* gpioMIDI = midiAndTimer->gpioMIDI;
	XScuTimer* timer = midiAndTimer->timer;
	XScuTimer_Stop(timer);
	noteIndex = 0;
	//被触发后播放音乐
	playSongIndex = OCMBuffer[CLOCK_MUSIC];
	const MusicNote* song = songList[playSongIndex].realSong;
	loadInterruptTime(song[noteIndex].Note,
					song[noteIndex].Beat,
					song[noteIndex].Dotted,
					songList[playSongIndex].playSpeed,
					songList[playSongIndex].playBeat);
	XGpio_DiscreteWrite(gpioMIDI,MIDI_CHANNEL,musicLevel);
	//加载数据
	XScuTimer_LoadTimer(timer,reloadTime);
	//开始播放音乐
	print("start clock %d\n\r",OCMBuffer[CLOCK_MUSIC]);
	OCMBuffer[IS_CLOCK_PLAY] = true;
	XScuTimer_Start(timer);
}

void SGICloseMusic(void* callback){
	XScuTimer* timer = (XScuTimer*)callback;
	noteIndex = 0;
	OCMBuffer[IS_CLOCK_PLAY] = false;
	XScuTimer_Stop(timer);
}

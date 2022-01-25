#include <stdio.h>
#include "MIDI.h"
#include "xil_mmu.h"

void SGIPlayClockMusic(void* callback);
void SGICloseMusic(void* callback);

int main(int argc,char** argv){
	//ȥ��OCM��cache����
	Xil_SetTlbAttributes(0xFFFF0000,0x14de2);
	XGpio gpioMIDI;
	int status = XST_SUCCESS;
	status = initMIDIDevice(&gpioMIDI);

	//GIC��˽�ж�ʱ��
	XScuGic gic;
	//��ʼ��GIC(ͨ���жϿ�����)
	status = initScuGicDevice(&gic);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	XScuTimer timer;
	//��ʼ��CPU1��˽�ж�ʱ��
	status = initPrivateTimerDevice(&timer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//�жϺ�����������
	gpioMIDIAndTimer midiAndTimer;
	midiAndTimer.gpioMIDI = &gpioMIDI;
	midiAndTimer.timer = &timer;

	//SGIע��

	//�жϺ�����
	status = setupMIDIInterrupt(&gic,&midiAndTimer);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//�쳣ע��
	initScuGicException(&gic);

	while(true){
		while(OCMBuffer[INTERRUPT_CPU1] == false);
		//��������
		if(OCMBuffer[INTERRUPT_CPU1] == 1){
			OCMBuffer[INTERRUPT_CPU1] = false;
			//�ȹر�����
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
			//��������
			XScuTimer_LoadTimer(&timer,reloadTime);
			//��ʼ��������
			print("start clock %d\n\r",OCMBuffer[CLOCK_MUSIC]);
			OCMBuffer[IS_CLOCK_PLAY] = true;
			XScuTimer_Start(&timer);
		}else if(OCMBuffer[INTERRUPT_CPU1] == 2){
			OCMBuffer[INTERRUPT_CPU1] = false;
			//�ر�����
			noteIndex = 0;
			OCMBuffer[IS_CLOCK_PLAY] = false;
			XScuTimer_Stop(&timer);
		}
//		//����flag,�����ȴ��ж�
//		OCMBuffer[INTERRUPT_CPU1] = false;
//		//���ڲ���������,����ر�
//		if(OCMBuffer[NEED_MUSIC_PLAY] == false){
//			//�ȹر�����
//			OCMBuffer[IS_CLOCK_PLAY] = false;
//			print("close\n\r");
//			XScuTimer_Stop(&timer);
//		}else{
//			noteIndex = 0;
//			//�������󲥷�����
//			playSongIndex = OCMBuffer[CLOCK_MUSIC];
//			const MusicNote* song = songList[playSongIndex].realSong;
//			loadInterruptTime(song[noteIndex].Note,
//					song[noteIndex].Beat,
//					song[noteIndex].Dotted,
//					songList[playSongIndex].playSpeed,
//					songList[playSongIndex].playBeat);
//			XGpio_DiscreteWrite(&gpioMIDI,MIDI_CHANNEL,musicLevel);
//			//��������
//			XScuTimer_LoadTimer(&timer,reloadTime);
//			//��ʼ��������
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
	//�������󲥷�����
	playSongIndex = OCMBuffer[CLOCK_MUSIC];
	const MusicNote* song = songList[playSongIndex].realSong;
	loadInterruptTime(song[noteIndex].Note,
					song[noteIndex].Beat,
					song[noteIndex].Dotted,
					songList[playSongIndex].playSpeed,
					songList[playSongIndex].playBeat);
	XGpio_DiscreteWrite(gpioMIDI,MIDI_CHANNEL,musicLevel);
	//��������
	XScuTimer_LoadTimer(timer,reloadTime);
	//��ʼ��������
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

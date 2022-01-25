#include "MIDI.h"

//��װʱ��
u32 reloadTime = 0;
//�����������
u32 noteCount = 0;
//�����������
u32 noteIndex = 0;
//���ָߵ͵�ƽ
volatile u8 musicLevel = 0;
//��ǰ������һ�׸�
volatile u8 playSongIndex = 0;

//GPIO MIDI��ʼ��
int initMIDIDevice(XGpio* gpioMIDI){
	int status = XST_SUCCESS;
	status = XGpio_Initialize(gpioMIDI,MIDI_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//���÷���Ϊ���
	XGpio_SetDataDirection(gpioMIDI,MIDI_CHANNEL,0);
	//��ʼ�������б�
	initSongList();
	return XST_SUCCESS;
}

//��������������װʱ��
u32 calNoteReloadTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat)
{
	if(note != KEY_NOP){
		//��5����Ϊԭ����Ƶ�ʶ�������10,������Ҫ��2�õ�0.5�����ڵ�ʱ��
		return TIMER_FRQ / note * 5 * dotted;
	}else{
		return TIMER_FRQ / beat / playSpeed * playBeat * 60 * dotted;
	}
}

//����������Ķ�ʱ���жϴ��������������Ϊ��ֹ����ֻ�ж�һ��
u32 calInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat){
	return calNoteReloadTime(0,beat,dotted,playSpeed,playBeat) / note;
}

//�������ö�ʱ���жϴ���,����ʱ���ж�ʱ��
void loadInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat){
	reloadTime = calNoteReloadTime(note,beat,dotted,playSpeed,playBeat);
	noteCount = calInterruptTime(reloadTime,beat,dotted,playSpeed,playBeat);
}

//�������ֵ��жϺ���
int setupMIDIInterrupt(XScuGic* gic,gpioMIDIAndTimer* midiAndTimer){
	XScuTimer* timer = midiAndTimer->timer;
	int status = XST_SUCCESS;
	//���ܲ��ǵ�һ��ע��,�����disconnect
	//29��˽�ж�ʱ���ж�
	status = XScuGic_Connect(gic, PRIVATE_TIMER_INTERRUPT_ID,
				(Xil_ExceptionHandler)midiInterruptHandler,
				midiAndTimer);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}
	//����29���ж�
	XScuGic_Enable(gic,PRIVATE_TIMER_INTERRUPT_ID);
	//����˽�ж�ʱ���Զ���װ
	XScuTimer_EnableAutoReload(timer);
	//����timer���ⷢ���ж��ź�
	XScuTimer_EnableInterrupt(timer);
	return XST_SUCCESS;
}

//�����жϺ���
void midiInterruptHandler(void* callbackRef){
	gpioMIDIAndTimer* midiAndTimer = (gpioMIDIAndTimer*)callbackRef;
	XGpio* gpioMIDI = midiAndTimer->gpioMIDI;
	XScuTimer* timer = midiAndTimer->timer;
	if(XScuTimer_IsExpired(timer)){
		//����ж�״̬
		XScuTimer_ClearInterruptStatus(timer);
		noteCount--;
		musicLevel = ~musicLevel;
		//��������Ѿ��������
		if(noteCount == 0){
			noteIndex++;
			if(noteIndex >= songList[playSongIndex].songLength){
				//ֹͣ����
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
		//�����������ƽ
		XGpio_DiscreteWrite(gpioMIDI,MIDI_CHANNEL,musicLevel);
	}
}

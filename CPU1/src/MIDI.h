#ifndef _MIDI_H_
#define _MIDI_H_

//����ͷ�ļ�
#include "song.h"
#include "zhmacro.h"

//GPIO�豸���궨��
#define MIDI_DEVICE_ID		XPAR_GPIO_MIDI_DEVICE_ID
#define MIDI_CHANNEL		CHANNEL1

//��װʱ��
extern u32 reloadTime;
//�����������
extern u32 noteCount;
//����index
extern u32 noteIndex;
//���ָߵ͵�ƽ
extern volatile u8 musicLevel;
//��ǰ������һ�׸�
extern volatile u8 playSongIndex;

typedef struct gpioMIDIAndTimer{
	XGpio* gpioMIDI;
	XScuTimer* timer;
}gpioMIDIAndTimer;

//GPIO MIDI��ʼ��
int initMIDIDevice(XGpio* gpioMIDI);
//����������װʱ��
u32 calNoteReloadTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat);
//����������Ķ�ʱ���жϴ���,���������Ϊ��ֹ����ֻ�ж�һ��
u32 calInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat);
//�������ö�ʱ���жϴ���,����ʱ���ж�ʱ��
void loadInterruptTime(u32 note,u8 beat,float dotted,u8 playSpeed,u8 playBeat);
//�������ֵ��жϺ���
int setupMIDIInterrupt(XScuGic* gic,gpioMIDIAndTimer* midiAndTimer);
//�����жϺ���
void midiInterruptHandler(void* callbackRef);

#endif

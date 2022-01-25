#ifndef _SONG_H_
#define _SONG_H_

#include "MusicNote.h"

typedef struct Song{
	const MusicNote* realSong;
	//�����ٶ�(255�Ѿ���Ӧ������Ұ�����)
	u8 playSpeed;
	//��������Ϊ1��
	u8 playBeat;
	//��������
	u32 songLength;
}Song;

//�����б�
Song songList[5];

//��ʼ�������б�
void initSongList();
//����������(ÿ����146��,4������Ϊ1��)
extern const MusicNote OdeToJoy[200];
//�궷������(ÿ����120��,4������Ϊ1��)
extern const MusicNote ContraForce[547];
//������������(ÿ����80��,4������Ϊ1��)
extern const MusicNote SuperMario[922];
//�׺�һ��Ц����(ÿ����60��,4������Ϊ1��)
extern const MusicNote TheVastSeaLaugh[642];
//���̰�����ʾ��
extern const MusicNote keyPressHint[2];
#endif

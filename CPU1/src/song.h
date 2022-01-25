#ifndef _SONG_H_
#define _SONG_H_

#include "MusicNote.h"

typedef struct Song{
	const MusicNote* realSong;
	//演奏速度(255已经可应对最快的野蜂飞舞)
	u8 playSpeed;
	//几分音符为1拍
	u8 playBeat;
	//歌曲长度
	u32 songLength;
}Song;

//音乐列表
Song songList[5];

//初始化音乐列表
void initSongList();
//欢乐颂曲谱(每分钟146拍,4分音符为1拍)
extern const MusicNote OdeToJoy[200];
//魂斗罗曲谱(每分钟120拍,4分音符为1拍)
extern const MusicNote ContraForce[547];
//超级玛丽曲谱(每分钟80拍,4分音符为1拍)
extern const MusicNote SuperMario[922];
//沧海一声笑曲谱(每分钟60拍,4分音符为1拍)
extern const MusicNote TheVastSeaLaugh[642];
//键盘按键提示音
extern const MusicNote keyPressHint[2];
#endif

#include "song.h"

void initSongList(){
	songList[0].realSong = OdeToJoy;
	songList[0].playSpeed = 146;
	songList[0].playBeat = 4;
	songList[0].songLength = 200;

	songList[1].realSong = ContraForce;
	songList[1].playSpeed = 120;
	songList[1].playBeat = 4;
	songList[1].songLength = 547;

	songList[2].realSong = SuperMario;
	songList[2].playSpeed = 80;
	songList[2].playBeat = 4;
	songList[2].songLength = 922;

	songList[3].realSong = TheVastSeaLaugh;
	songList[3].playSpeed = 60;
	songList[3].playBeat = 4;
	songList[3].songLength = 642;

	songList[4].realSong = keyPressHint;
	songList[4].playSpeed = 60;
	songList[4].playBeat = 4;
	songList[4].songLength = 2;
}

//欢乐颂曲谱
const MusicNote OdeToJoy[200] = {
	{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},                //|0 0 0 0|
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|3 3 4 5|
	{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|5 4 3 2|
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|1 1 2 3|
	{KEY_e2,Beat_1Q4,1.4},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q4,0.1},                                                       //|3.2/ 2-|
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|3 3 4 5|
	{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|5 4 3 2|
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|1 1 2 3|
	{KEY_d2,Beat_1Q4,1.4},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q4,0.2},                                                       //|2. 1/ 1-|
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|2 2 3 1|
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},                                                       //|2 34/ 3 1|
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},//|2 34/ 3 2|
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_g1,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|1 2 5# 3|
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|3 3 4 5|
	{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},                                                       //|5 4 3 42/|
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|1 1 2 3|
	{KEY_d2,Beat_1Q4,1.4},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q4,0.2},                                                       //|2. 1/ 1-|
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|2 2 3 1|
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},                                                       //|2 34/ 3 1|
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},//|2 34/ 3 2|
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_g1,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|1 2 5# 3|
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|3 3 4 5|
	{KEY_g2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_f2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},                                                       //|5 4 3 42/|
	{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},{KEY_e2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},          //|1 1 2 3|
	{KEY_d2,Beat_1Q4,1.4},{KEY_NOP,Beat_1Q4,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q4,0.2}                                                        //|2. 1/ 1-|
};

//魂斗罗曲谱
const MusicNote ContraForce[547] = {
	{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},//|0 0 0 0|
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a1g1e1d1// e1d1c1b// c1bag// adeg//|
	{KEY_a,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},
	{KEY_a,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a- a/e10// d1//e1/Sf1//|
	{KEY_g1,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1},//|g1---|
	{KEY_a,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},
	{KEY_a,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a- a/e10// d1//e1/Sf1//|
	{KEY_c1,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1},//|c1---|
	{KEY_a,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},
	{KEY_a,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a- a/e10// d1//e1/Sf1//|
	{KEY_g1,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1},//|g1---|
	{KEY_a,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},
	{KEY_a,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a- a/e10// d1//e1/Sf1//|
	{KEY_c1,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1},//|c1---|
	{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_e1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},{KEY_f1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},
	{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q16,1},//|e10// e1.Sf1./ g10g1// 0 0//|
	{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_f1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},{KEY_g1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|Sf10// f1.g1./ a10a10// g1//a1./|
	{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_e1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},{KEY_f1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},
	{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q16,1},//|e10// e1.Sf1./ g10g1// 0 0//|
	{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_f1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},{KEY_g1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},
	{KEY_a1,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d2,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},//|Sf10// f1.g1./ a1 d2|
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sc2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sc1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|b1a1Sf2e2// d2Sc2b1a1// b1a1Sf1e1// f1e1d1Sc1//|
	{KEY_e,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},{KEY_NOP,Beat_1Q16,1},
	{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sf,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|e./0// e//Sf/g// b0a0// g//f/d//|
	{KEY_e,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1},//|e---|
	{KEY_Sc,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},
	{KEY_Sf,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|Sc d//e./ Sf g//a./|
	{KEY_b,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_Sc1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_Sf1,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|b Sc1//d1/e1// Sf1 e1ega//|
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_b,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sc1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|babe// 0ega// b/d1Sc1// d1//c1/a//|
	{KEY_b,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1},//|b---|
	{KEY_Sc,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_d,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},
	{KEY_Sf,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|Sc d//e./ Sf g//a./|
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sc1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_Sf1,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},
	{KEY_e1,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},//|bbb0// b//Sc1/d1// Sf1 e1|
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sc1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|d1d1d1d1// 0/d1d1// d1d10d1// 0//Sc1./|
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sc1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|bbbb// 0/bb// bb0b// 0//Sc1./|
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sc1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|d1d1d1d1// 0/d1d1// d1d10d1// 0//Sc1./|
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sc1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sc1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|bbbb// 0/bSc1// d1e1Sf1e1// 0//Sc1./|
	{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|Sf1f1f1f1// 0/f1f1// f1f10f1// 0//e1./|
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|d1d1d1d1// 0/d1d1// d1d10d1// 0//e1./|
	{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_f1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|Sf1f1f1f1// 0/f1f1// f1f10f1// 0//g1./|
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,3},{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a1a1a1a1// 0/a1a1// a1a1//0./ega//|
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sc1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|bab//e/ega// bab//d1/d1Sc1d1//|
	{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_b,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_Sc1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_d1,Beat_1Q16,2.7},{KEY_NOP,Beat_1Q16,0.3},//|bab//e/ega// 0b0Sc1// 0//d1./|
	{KEY_a1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},
	{KEY_a,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_d1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_Sf1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a- a/e10// d1//e1/Sf1//|
	{KEY_g1,Beat_1Q1,0.9},{KEY_NOP,Beat_1Q1,0.1}//|g1---|
};

//超级玛丽
const MusicNote SuperMario[922] = {
	{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},//|0 0 0 0|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//3/3// 01//3/ 50/ 5#0/|
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sa1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|1/05#// 0#3/ 0//6#/7#// 0b7#//6#/|
	{KEY_g1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},//|#535/ 6/45// 0//3/1// 2//7#/0//|
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sa1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|1/05#// 03/ 0//6#/7#// 0b7#//6#/|
	{KEY_g1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},//|#535/ 6/45// 0//3/1// 2//7#/0//|
	{KEY_NOP,Beat_1Q8,1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sd2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sg1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|0/5b5// 4//b3/3// 0b6#6#1// 06#12//|
	{KEY_NOP,Beat_1Q8,1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sd2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c3,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c3,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c3,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1}, //|0/5b5// 4//b3/3// 0//#1/#1// #10/|
	{KEY_NOP,Beat_1Q8,1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sd2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sg1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|0/5b5// 4//b3/3// 0b6#6#1// 06#12//|
	{KEY_NOP,Beat_1Q8,1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1},//|05/ 0//4/0// 30/ 0|
	{KEY_NOP,Beat_1Q8,1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sd2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sg1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|0/5b5// 4//b3/3// 0b6#6#1// 06#12//|
	{KEY_NOP,Beat_1Q8,1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sd2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c3,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c3,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c3,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|0/5b5// 4//b3/3// 0//#1/#1// #10/|
	{KEY_NOP,Beat_1Q8,1},{KEY_Sf2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_Sd2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sg1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|0/5b5// 4//b3/3// 0b6#6#1// 06#12//|
	{KEY_NOP,Beat_1Q8,1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1},//|05/ 0//4/0// 30/ 0|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|1//1/1// 01//2/ 3//1/6#// 5#0/|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q4,1},
	{KEY_NOP,Beat_1Q4,1},//|1//1/1// 0123// 0 0|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|1//1/1// 01//2/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//3/3// 01//3/ 50/ 5#0/|
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_e1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sa1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|1/05#// 0#3/ 0//6#/7#// 0b7#//6#/|
	{KEY_g1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},//|#535/ 6/45// 0//3/1// 2//7#/0//|
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_Sa1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|1/05#// 03/ 0//6#/7#// 0b7#//6#/|
	{KEY_g1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_b1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q16,1},                                                 //|#535/ 6/45// 0//3/1// 2//7#/0//|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|7#66/ 654/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_d2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1},//|7#//4/4// 432/ 10/ 0|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|7#66/ 654/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_d2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1},//|7#//4/4// 432/ 10/ 0|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|1//1/1// 01//2/ 3//1/6#// 5#0/|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q4,1},
	{KEY_NOP,Beat_1Q4,1}, //|1//1/1// 0123// 0 0|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|1//1/1// 01//2/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//3/3// 01//3/ 50/ 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|7#66/ 654/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_d2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1},//|7#//4/4// 432/ 10/ 0|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|7#66/ 654/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_d2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1},//|7#//4/4// 432/ 10/ 0|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|1//1/1// 01//2/ 3//1/6#// 5#0/|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q4,1},
	{KEY_NOP,Beat_1Q4,1},//|1//1/1// 0123// 0 0|
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|1//1/1// 01//2/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q16,1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//3/3// 01//3/ 50/ 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_a2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_g2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|7#66/ 654/ 3//1/6#// 5#0/|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_NOP,Beat_1Q8,1},{KEY_Sg1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},//|3//1/5#// 0b6#/ 6#//4/4// 6#0/|
	{KEY_b1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_f2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_f2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_f2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_e2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},{KEY_d2,Beat_1Q4,0.3},{KEY_NOP,Beat_1Q4,0.03},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_NOP,Beat_1Q8,1},
	{KEY_NOP,Beat_1Q4,1}//|7#//4/4// 432/ 10/ 0|
};

//沧海一声笑曲谱
const MusicNote TheVastSeaLaugh[642] = {
	{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},{KEY_NOP,Beat_1Q4,1},
	{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c3,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d3,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g3,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d3,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c3,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d3,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g3,Beat_1Q4,0.9},{KEY_NOP,Beat_1Q4,0.1},//|g2a2c3d3// g3d3/ g2a2c3d3// g3|
	//主旋律1
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2/ c2-|
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2/e2d2// c2a1/ g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/|
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2//c2/ d2-|
	//主旋律2
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2.d2/ c2-|
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2/e2d2// c2a1/ g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/|
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2//c2/ d2-|
	//主旋律3
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2/ c2-|
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2.d2/ c2/a1g1// g1-|
	{KEY_g1,Beat_1Q16,1.4},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/|
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2e2c2// d2-|
	//主旋律4
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2/ c2-|
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2.d2/ c2/a1g1// g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1g1a1// c2.d2/ e2g2/|
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2//c2/ c2-|
	//引子
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a1c2d2e2// a1c2d2e2// a1c2d2e2// a1c2d2e2//|
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a1c2d2e2// a1c2d2e2// a1c2d2e2// a1c2d2e2//|
	//间奏
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2/ c2-|
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2g2e2d2// c2a1/ g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/|
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/g2a2// g2e2d2c2// d2-|
	//主旋律5
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2g2e2d2// c2-|
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2.d2/ c2d2c2a1// g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1g1a1// c2.d2/ e2g2/|
	{KEY_a2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_g2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2/a2g2// e2d2//c2/ c2-|
	//引子
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a1c2d2e2// a1c2d2e2// a1c2d2e2// a1c2d2e2//|
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_a1,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},//|a1c2d2e2// a1c2d2e2// a1c2d2e2// a1c2d2e2//|
	//主旋律6哼唱
	{KEY_a2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_g2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2.g2/ e2d2/ c2-|
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2.d2/ c2a1/ g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/ |
	{KEY_a2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_g2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2.g2/ e2d2//c2/ d2-|
	//主旋律6哼唱
	{KEY_a2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_g2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2.g2/ e2d2/ c2-|
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2.d2/ c2a1/ g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/ |
	{KEY_a2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_g2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2.g2/ e2d2//c2/ d2-|
	//主旋律6哼唱
	{KEY_a2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_g2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_d2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|a2.g2/ e2d2/ c2-|
	{KEY_e2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_g1,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1},//|e2.d2/ c2a1/ g1-|
	{KEY_g1,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_a1,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_g1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_a1,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_c2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_d2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},{KEY_g2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},//|g1.a1/ g1a1/ c2.d2/ e2g2/ |
	{KEY_a2,Beat_1Q8,1.35},{KEY_NOP,Beat_1Q8,0.15},{KEY_g2,Beat_1Q16,1},{KEY_NOP,Beat_1Q16,0.1},
	{KEY_e2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_d2,Beat_1Q16,0.9},{KEY_NOP,Beat_1Q16,0.1},{KEY_c2,Beat_1Q8,0.9},{KEY_NOP,Beat_1Q8,0.1},
	{KEY_d2,Beat_1Q2,0.9},{KEY_NOP,Beat_1Q2,0.1}//|a2.g2/ e2d2//c2/ d2-|
};

//键盘按键提示音
const MusicNote keyPressHint[2] = {
		{KEY_a1,Beat_1Q16,0.9},{KEY_b1,Beat_1Q16,0.1},
};

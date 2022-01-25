#ifndef _MUSICNOTE_H_
#define _MUSICNOTE_H_
//音符头文件
#include "xil_exception.h"

//钢琴琴键10倍频率，每秒中断间隔次数的5倍
#define KEY_A2   275
#define KEY_SA2  291
#define KEY_B2   309
#define KEY_C1   327
#define KEY_SC1  346
#define KEY_D1   367
#define KEY_SD1  389
#define KEY_E1   412
#define KEY_F1   437
#define KEY_SF1  462
#define KEY_G1   490
#define KEY_SG1  519
#define KEY_A1   550
#define KEY_SA1  583
#define KEY_B1   617
#define KEY_C    654
#define KEY_SC   693
#define KEY_D    734
#define KEY_SD   778
#define KEY_E    824
#define KEY_F    873
#define KEY_SF   925
#define KEY_G    980
#define KEY_SG   1038
#define KEY_A    1100
#define KEY_SA   1165
#define KEY_B    1235
#define KEY_c    1308
#define KEY_Sc   1386
#define KEY_d    1468
#define KEY_Sd   1556
#define KEY_e    1648
#define KEY_f    1746
#define KEY_Sf   1850
#define KEY_g    1960
#define KEY_Sg   2077
#define KEY_a    2200
#define KEY_Sa   2331
#define KEY_b    2469
#define KEY_c1   2616      //中音
#define KEY_Sc1  2772
#define KEY_d1   2937
#define KEY_Sd1  3111
#define KEY_e1   3296
#define KEY_f1   3492
#define KEY_Sf1  3700
#define KEY_g1   3920
#define KEY_Sg1  4153
#define KEY_a1   4400
#define KEY_Sa1  4662
#define KEY_b1   4939
#define KEY_c2   5233
#define KEY_Sc2  5544
#define KEY_d2   5873
#define KEY_Sd2  6223
#define KEY_e2   6593
#define KEY_f2   6985
#define KEY_Sf2  7400
#define KEY_g2   7840
#define KEY_Sg2  8306
#define KEY_a2   8800
#define KEY_Sa2  9323
#define KEY_b2   9878
#define KEY_c3   10470
#define KEY_Sc3  11090
#define KEY_d3   11750
#define KEY_Sd3  12450
#define KEY_e3   13190
#define KEY_f3   13970
#define KEY_Sf3  14800
#define KEY_g3   15680
#define KEY_Sg3  16610
#define KEY_a3   17600
#define KEY_Sa3  18650
#define KEY_b3   19760
#define KEY_c4   20930
#define KEY_Sc4  22170
#define KEY_d4   23490
#define KEY_Sd4  24890
#define KEY_e4   26370
#define KEY_f4   27940
#define KEY_Sf4  29600
#define KEY_g4   31360
#define KEY_Sg4  33220
#define KEY_a4   35200
#define KEY_Sa4  37290
#define KEY_b4   39510
#define KEY_c5   41860
#define KEY_NOP  0
//几分音符
#define Beat_1Q1   1
#define Beat_1Q2   2
#define Beat_1Q4   4
#define Beat_1Q8   8
#define Beat_1Q16 16

//音符结构
typedef struct MusicNote{
	//音符频率,乘以10了
	u32 Note;
	//几分音符
	u8  Beat;
	//延迟
	float Dotted;
}MusicNote;


#endif

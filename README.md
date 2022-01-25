# CQU 嵌入式体系结构期末项目——电子时钟

## 1. 本项目采用AMP架构的双CPU

> CPU0负责键盘扫描、DS1302通信、七段数码管的显示  
> CPU1负责播放键盘声和闹钟音乐  

程序运行后CPU0将唤醒CPU1,并从DS1302中的RAM读取已设置的闹钟和时间  
按下按键后CPU0将写入OCMBuffer中的数据,通知CPU1播放音乐

## 2. 项目结构为

```cpp
FinalProgram
│-- README.md   
    |-- CPU0
    |   |-- .cproject
    |   |-- .project
    |   |-- src
    |       |-- KEYS.h
    |       │-- KEYS.c
    |       |-- DS1302.h
    |       |-- DS1302.c
    |       |-- LED.h
    |       |-- LED.c
    |       |-- GicAndTimer.h
    |       |-- GicAndTimer.c
    |       |-- zhmacro.h
    |       |-- main.c
    |       |-- lscript.ld
    |       |-- Xilinx.sepc
    |       └───
    |-- CPU1
    |   |-- .cproject
    |   |-- .project
    |   |-- src
    |       │-- MIDI.h
    |       │-- MIDI.c
    |       |-- GicAndTimer.h
    |       |-- GicAndTimer.c
    |       |-- MusicNode.h
    |       |-- song.h
    |       |-- song.c
    |       |-- zhmacro.h
    |       |-- main.c
    |       |-- lscript.ld
    |       |-- Xilinx.sepc
    |       └───
```

## 3. 5 x 4键盘功能设计如下

| 功能 | 功能 | 功能 | 功能 |
|:---:|:---:|:---:|:---:|
| 闹钟1 | 闹钟2 | 闹钟3 | 闹钟4 |
| 保存修改 | 取消修改 | 上一首音乐 | 下一首音乐 |
| 前一个位置(循环) | 后一个位置(循环) | 进入(退出)音乐预览模式 | 进入设置模式 |
| 减操作 | 加操作 | 显示时间(年月日) | 显示学号 |
| 音乐1 | 音乐2 | 音乐3 | 音乐4 |

## 4. CPU0和CPU1通过OCM进行通信,OCMBuffer定义在zhmacro.h中

## 5. 不足之处

> 所有设计的API均需要提供XGpio或XScuGic或XScuTimer等设备指针,使用时较为复杂  
> 键盘程序中的状态使用了多个u8型数据进行指示,应改进为一个u8型数据并使用DFA进行状态间的转换  

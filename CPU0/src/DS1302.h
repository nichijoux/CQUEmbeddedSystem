#ifndef _DS1302_H_
#define _DS1302_H_

#include "xil_exception.h"
#include "zhmacro.h"

//DS1302�豸ID
#define DS1302_DEVICE_ID XPAR_GPIO_DS1302_DEVICE_ID
//ͨ��
#define IO_CHANNEL 		CHANNEL1
#define SCLKCE_CHANNEL 	CHANNEL2

//DS1302 �Ĵ���������
#define SECOND_MASK 0x7F
#define MINUTE_MASK 0x7F
#define HOUR_MASK 	0x1F
#define DATE_MASK	0x3F
#define MONTH_MASK	0x1F
#define YEAR_MASK	0xFF

//DS1302 ͨ������RST(CE)�ߺ�SCLK��
#define DS1302_RST_ON			0x01
#define DS1302_SCLK_ON			0x02
#define DS1302_RST_SCLK_ON		0x03
#define DS1302_RST_SCLK_OFF		0x00
#define BITMASK					0x01
//DS1302�Ĵ���,���Ϊread�����bitΪΪ1,���Ϊд��Ϊ0
#define DS1302_SECOND			0x80
#define DS1302_MINUTE 			0x82
#define DS1302_HOUR 			0x84
#define DS1302_DATE				0x86
#define DS1302_MONTH			0x88
#define DS1302_DAY				0x8A
#define DS1302_YEAR				0x8C
#define DS1302_WRITE_PROTECT 	0x8E
#define DS1302_TRICKLE			0x90
//����д����
#define OPEN_WRITE_PROTECT		0x80
#define CLOSE_WRITE_PROTECT		0x00

//DS1302 RAM�Ļ���ַ
#define DS1302_BASE_RAM				0xC0
#define getDS1302RAM(i)				(DS1302_BASE_RAM + (i << 1))
//�洢���ӵ�16��RAM
#define DS1302_BASE_SECOND_RAM		getDS1302RAM(8)
#define DS1302_BASE_MINUTE_RAM		getDS1302RAM(9)
#define DS1302_BASE_HOUR_RAM		getDS1302RAM(10)
#define DS1302_BASE_CLOCKMUSIC_RAM	getDS1302RAM(11)
//DS1302 �洢���ӵ�RAM
#define getDS1302_CLOCK_HOUR(i)			(DS1302_BASE_HOUR_RAM + (i * 8))
#define getDS1302_CLOCK_MINUTE(i)		(DS1302_BASE_MINUTE_RAM + (i * 8))
#define getDS1302_CLOCK_SECOND(i)		(DS1302_BASE_SECOND_RAM + (i * 8))
#define getDS1302_CLOCK_CLOCKMUSIC(i)	(DS1302_BASE_CLOCKMUSIC_RAM + (i * 8))
//�洢��ʼʱ���RAM
#define getInitHour()		getDS1302RAM(25)
#define getInitMinute()		getDS1302RAM(26)
#define getInitSecond()		getDS1302RAM(27)
#define getInitYear()		getDS1302RAM(28)
#define getInitMonth()		getDS1302RAM(29)
#define getInitDate()		getDS1302RAM(30)

//����
volatile u8 setClockHour[4];
volatile u8 setClockMinute[4];
volatile u8 setClockSecond[4];
volatile u8 setClockMusic[4];

//DS1302 API

//BCD���10��������ת��
u8 BCDToDEC(u8 value);
u8 DECToBCD(u8 value);
//��ʼ��������
void startTransform(XGpio* gpioDS1302);
//�رմ�������
void endTransform(XGpio* gpioDS1302);

//DS1302д���ֽ�
void writeDS1302Byte(XGpio* gpioDS1302,u8 address,u8 value);
//DS1302�����ֽ�
u8 readDS1302Byte(XGpio* gpioDS1302,u8 address);

//��ʼ��GPIO
int initDS1302Device(XGpio* gpioDS1302);

#endif

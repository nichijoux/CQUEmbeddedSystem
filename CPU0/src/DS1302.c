#include "DS1302.h"

const u8 defaultDS1302Address[] = {
		DS1302_SECOND,
		DS1302_MINUTE,
		DS1302_HOUR,
		DS1302_DATE,
		DS1302_MONTH,
		DS1302_DAY,
		DS1302_YEAR,
		DS1302_WRITE_PROTECT
};

//BCD����10����������໥ת��
inline u8 BCDToDEC(u8 value) {
	return (value & 0x0F) + ((value >> 4) * 10);
}

inline u8 DECToBCD(u8 value) {
	return (value / 10 << 4) | value % 10;
}

//��ʼ��������
void startTransform(XGpio* gpioDS1302){
	//��RST SCLKȫ����Ϊ�͵�ƽ(��ʼ��)
	XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_OFF);
	//Ȼ��RST��Ϊ�ߵ�ƽ,׼����ʼ��������
	XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
}

//�رմ�������
void endTransform(XGpio* gpioDS1302){
	//��RST SCLKȫ����Ϊ�͵�ƽ,�����˴�ͨ��
	XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_OFF);
}

//DS1302��Ĵ�����д���ֽ�
void writeDS1302Byte(XGpio* gpioDS1302,u8 address, u8 value)
{
	startTransform(gpioDS1302);

	//дָ���ֽ�,�ӵ�bitλ��ʼ����
	u8 bitValue = 0x0;
	for(int i = 0; i < 8;i++)
	{
		bitValue = (address >> i) & BITMASK;
		//��ͨ��1д������,GpioDS1302��ͨ��һ��ΪIO��
		XGpio_DiscreteWrite(gpioDS1302, IO_CHANNEL, bitValue);
		//��SCL��Ϊ�ߵ�ƽ
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//��SCLK�õ͵�ƽ
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
	}

	//д�ֽ�
	bitValue = 0x0;
	for(int i = 0; i<8;i++)
	{
		//ÿ��ֻ����1bit
		bitValue = (value >> i) & BITMASK;
		XGpio_DiscreteWrite(gpioDS1302, IO_CHANNEL, bitValue);
		//��SCLK�øߵ�ƽ
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//��SCLK�õ͵�ƽ
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
	}

	endTransform(gpioDS1302);
}

//DS1302��Ĵ����ж����ֽ�
u8 readDS1302Byte(XGpio* gpioDS1302,u8 address)
{
	//��֤�õ�ַ�����ڶ�ȡ���ݵ�
	address = address | 0x01;
	u8 retval = 0x00;

	startTransform(gpioDS1302);

	//дָ���ֽ�,�ӵ�bitλ��ʼ����
	u8 bitValue = 0x0;
	for(int i = 0; i<8; i++)
	{
		bitValue = (address >> i) & BITMASK;
		//��ͨ��1д������,GpioDS1302��ͨ��һ��ΪIO��
		XGpio_DiscreteWrite(gpioDS1302, IO_CHANNEL, bitValue);
		//��SCL��Ϊ�ߵ�ƽ
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//��SCLK�õ͵�ƽ
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
	}

	//��real Data
	bitValue = 0x0;
	//����ͨ��һΪread
	XGpio_SetDataDirection(gpioDS1302, IO_CHANNEL, 0xFF);
	for(int i = 0; i < 8;i++)
	{
		//��IOͨ����ȡbit����
		bitValue = XGpio_DiscreteRead(gpioDS1302, IO_CHANNEL);

		//����iΪ��ΪbitValue
		retval ^= (-bitValue ^ retval) & (1 << i);

		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);

	}

	endTransform(gpioDS1302);
	//����ͨ��һΪwrite
	XGpio_SetDataDirection(gpioDS1302, IO_CHANNEL, 0x0);
	return retval;
}

//DS1302��ʼ��
int initDS1302Device(XGpio* gpioDS1302){
	int status = XST_SUCCESS;
	status = XGpio_Initialize(gpioDS1302,DS1302_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//���÷���
	XGpio_SetDataDirection(gpioDS1302,IO_CHANNEL,0);
	XGpio_SetDataDirection(gpioDS1302,SCLKCE_CHANNEL,0);
	//ȫ����Ϊ�͵�ƽ�ȴ�
	XGpio_DiscreteWrite(gpioDS1302,SCLKCE_CHANNEL,DS1302_RST_SCLK_OFF);
	//���д����
	writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
//  RAM��ȡ��ɲ����ٴζ�ȡ
	//��ʼ��ʱ��
	writeDS1302Byte(gpioDS1302,getInitHour(),0x12);
	writeDS1302Byte(gpioDS1302,getInitMinute(),0x30);
	writeDS1302Byte(gpioDS1302,getInitSecond(),0x00);
	//д������
	writeDS1302Byte(gpioDS1302,getInitYear(),0x21);
	writeDS1302Byte(gpioDS1302,getInitMonth(),0x12);
	writeDS1302Byte(gpioDS1302,getInitDate(),0x25);
	u8 data = readDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(0));
	//���data������A��B��C��D����������
	if((data & 0x0F) > 9){
		//�������
		for(int i = 0;i < 4;i++){
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(i),0);
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_MINUTE(i),0);
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_SECOND(i),0);
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_CLOCKMUSIC(i),0);
		}
	}

	//RAM�ж�ȡ
	u8 hour = readDS1302Byte(gpioDS1302,getInitHour());
	u8 minute = readDS1302Byte(gpioDS1302,getInitMinute());
	u8 second = readDS1302Byte(gpioDS1302,getInitSecond());
	u8 year = readDS1302Byte(gpioDS1302,getInitYear());
	u8 month = readDS1302Byte(gpioDS1302,getInitMonth());
	u8 date = readDS1302Byte(gpioDS1302,getInitDate());


	//��ʼ��ʱ��
	writeDS1302Byte(gpioDS1302,DS1302_HOUR,hour);
	writeDS1302Byte(gpioDS1302,DS1302_MINUTE,minute);
	writeDS1302Byte(gpioDS1302,DS1302_SECOND,second);
	//д������
	writeDS1302Byte(gpioDS1302,DS1302_YEAR,year);
	writeDS1302Byte(gpioDS1302,DS1302_MONTH,month);
	writeDS1302Byte(gpioDS1302,DS1302_DATE,date);

	//д��ѧ��
	u8 studentID[] = {2,0,1,9,1,6,9,2};
	for(int i = 0;i < 8;i++){
		writeDS1302Byte(gpioDS1302,getDS1302RAM(i),studentID[i]);
	}

	//д��д����
	writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
	return XST_SUCCESS;
}

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

//BCD码与10进制数间的相互转换
inline u8 BCDToDEC(u8 value) {
	return (value & 0x0F) + ((value >> 4) * 10);
}

inline u8 DECToBCD(u8 value) {
	return (value / 10 << 4) | value % 10;
}

//开始传输数据
void startTransform(XGpio* gpioDS1302){
	//将RST SCLK全部置为低电平(初始化)
	XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_OFF);
	//然后将RST置为高电平,准备开始传输数据
	XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
}

//关闭传输数据
void endTransform(XGpio* gpioDS1302){
	//将RST SCLK全部置为低电平,结束此次通信
	XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_OFF);
}

//DS1302向寄存器中写单字节
void writeDS1302Byte(XGpio* gpioDS1302,u8 address, u8 value)
{
	startTransform(gpioDS1302);

	//写指令字节,从低bit位开始发送
	u8 bitValue = 0x0;
	for(int i = 0; i < 8;i++)
	{
		bitValue = (address >> i) & BITMASK;
		//向通道1写入数据,GpioDS1302的通道一即为IO口
		XGpio_DiscreteWrite(gpioDS1302, IO_CHANNEL, bitValue);
		//将SCL置为高电平
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//将SCLK置低电平
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
	}

	//写字节
	bitValue = 0x0;
	for(int i = 0; i<8;i++)
	{
		//每次只发送1bit
		bitValue = (value >> i) & BITMASK;
		XGpio_DiscreteWrite(gpioDS1302, IO_CHANNEL, bitValue);
		//将SCLK置高电平
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//将SCLK置低电平
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
	}

	endTransform(gpioDS1302);
}

//DS1302向寄存器中读单字节
u8 readDS1302Byte(XGpio* gpioDS1302,u8 address)
{
	//保证该地址是用于读取数据的
	address = address | 0x01;
	u8 retval = 0x00;

	startTransform(gpioDS1302);

	//写指令字节,从低bit位开始发送
	u8 bitValue = 0x0;
	for(int i = 0; i<8; i++)
	{
		bitValue = (address >> i) & BITMASK;
		//向通道1写入数据,GpioDS1302的通道一即为IO口
		XGpio_DiscreteWrite(gpioDS1302, IO_CHANNEL, bitValue);
		//将SCL置为高电平
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		//将SCLK置低电平
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
		//delay
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);
	}

	//读real Data
	bitValue = 0x0;
	//设置通道一为read
	XGpio_SetDataDirection(gpioDS1302, IO_CHANNEL, 0xFF);
	for(int i = 0; i < 8;i++)
	{
		//从IO通道读取bit数据
		bitValue = XGpio_DiscreteRead(gpioDS1302, IO_CHANNEL);

		//将第i为置为bitValue
		retval ^= (-bitValue ^ retval) & (1 << i);

		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_SCLK_ON);
		XGpio_DiscreteWrite(gpioDS1302, SCLKCE_CHANNEL, DS1302_RST_ON);

	}

	endTransform(gpioDS1302);
	//设置通道一为write
	XGpio_SetDataDirection(gpioDS1302, IO_CHANNEL, 0x0);
	return retval;
}

//DS1302初始化
int initDS1302Device(XGpio* gpioDS1302){
	int status = XST_SUCCESS;
	status = XGpio_Initialize(gpioDS1302,DS1302_DEVICE_ID);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}
	//设置方向
	XGpio_SetDataDirection(gpioDS1302,IO_CHANNEL,0);
	XGpio_SetDataDirection(gpioDS1302,SCLKCE_CHANNEL,0);
	//全部置为低电平等待
	XGpio_DiscreteWrite(gpioDS1302,SCLKCE_CHANNEL,DS1302_RST_SCLK_OFF);
	//清除写保护
	writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,CLOSE_WRITE_PROTECT);
//  RAM读取后可不用再次读取
	//初始化时间
	writeDS1302Byte(gpioDS1302,getInitHour(),0x12);
	writeDS1302Byte(gpioDS1302,getInitMinute(),0x30);
	writeDS1302Byte(gpioDS1302,getInitSecond(),0x00);
	//写入日期
	writeDS1302Byte(gpioDS1302,getInitYear(),0x21);
	writeDS1302Byte(gpioDS1302,getInitMonth(),0x12);
	writeDS1302Byte(gpioDS1302,getInitDate(),0x25);
	u8 data = readDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(0));
	//如果data数据有A、B、C、D则重置闹钟
	if((data & 0x0F) > 9){
		//清除闹钟
		for(int i = 0;i < 4;i++){
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_HOUR(i),0);
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_MINUTE(i),0);
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_SECOND(i),0);
			writeDS1302Byte(gpioDS1302,getDS1302_CLOCK_CLOCKMUSIC(i),0);
		}
	}

	//RAM中读取
	u8 hour = readDS1302Byte(gpioDS1302,getInitHour());
	u8 minute = readDS1302Byte(gpioDS1302,getInitMinute());
	u8 second = readDS1302Byte(gpioDS1302,getInitSecond());
	u8 year = readDS1302Byte(gpioDS1302,getInitYear());
	u8 month = readDS1302Byte(gpioDS1302,getInitMonth());
	u8 date = readDS1302Byte(gpioDS1302,getInitDate());


	//初始化时间
	writeDS1302Byte(gpioDS1302,DS1302_HOUR,hour);
	writeDS1302Byte(gpioDS1302,DS1302_MINUTE,minute);
	writeDS1302Byte(gpioDS1302,DS1302_SECOND,second);
	//写入日期
	writeDS1302Byte(gpioDS1302,DS1302_YEAR,year);
	writeDS1302Byte(gpioDS1302,DS1302_MONTH,month);
	writeDS1302Byte(gpioDS1302,DS1302_DATE,date);

	//写入学号
	u8 studentID[] = {2,0,1,9,1,6,9,2};
	for(int i = 0;i < 8;i++){
		writeDS1302Byte(gpioDS1302,getDS1302RAM(i),studentID[i]);
	}

	//写入写保护
	writeDS1302Byte(gpioDS1302,DS1302_WRITE_PROTECT,OPEN_WRITE_PROTECT);
	return XST_SUCCESS;
}

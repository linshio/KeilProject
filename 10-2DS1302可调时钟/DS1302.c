#include <REGX52.H>
//定义时间的地址信息
#define DS1302_SECOND 		0x80
#define DS1302_MINUTE 		0x82
#define DS1302_HOUR 		0x84
#define DS1302_DATE 		0x86
#define DS1302_MONTH 		0x88
#define DS1302_DAY 			0x8A
#define DS1302_YEAR 		0x8C
#define DS1302_WP	 		0x8E
//声明写入函数
void DS1302_WriteByte(unsigned char Commond,Data);
//时间芯片地址IO口
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;
//存储时间数组
unsigned char DS1302_Time[] = {25,02,22,10,50,11};
//时间的初始化
void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SCLK=0;
	//解除写保护状态
	DS1302_WriteByte(0x8E,0x00);
}
//向指定的地址输出数据
void DS1302_WriteByte(unsigned char Commond,Data)
{
	unsigned char i;
	DS1302_CE=1;
	//将第n位取出来赋值给IO
	for(i=0;i<8;i++)
	{
		DS1302_IO=Commond&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}
//向指定的地址读取数据
unsigned char DS1302_ReadByte(unsigned char Commond)
{
	unsigned char i,Data=0x00;
	Commond|=0x01;
	DS1302_CE=1;
	//将第n位取出来赋值给IO
	for(i=0;i<8;i++)
	{
		DS1302_IO=Commond&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO)
		{
			Data|=(0x01<<i);
		}
	}
	DS1302_CE=0;
	DS1302_IO=0;
	return Data;
}

void DS1302_SetTime(void)	
{
	//解除写保护状态
	DS1302_WriteByte(DS1302_WP,0x00);
	//此处的计算为十进制编码转换为BCD编码
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0x80);
}

void DS1302_ReadTime(void)
{
	unsigned char Temp;
	//此处的计算为BCD编码转换为十进制编码
	Temp = DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5] = Temp/16*10+Temp%16;
	Temp = DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6] = Temp/16*10+Temp%16;
	
}

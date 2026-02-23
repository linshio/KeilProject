#include <REGX52.H>
#include "Delay.h"
#define MATRIX_LED_PORT P0
sbit RCK = P3^5;//RCLK
sbit SCK = P3^6;//SRCLK
sbit SER = P3^4;//SER
//写入74HC595一个字节
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		//读取Byte的值与SER按位取
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

//LED点阵屏显示一列数据
//Column需要显示的列 范围0-7 0在最左边
//Data每列需要显示的数据 高位在上，1为亮，0为灭
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	Delay(1);
	//复位 
	MATRIX_LED_PORT=0xFF;
}
void main()
{
	//由于单片机io口是高电平所以要先将SCK与RCK赋值位0
	SCK=0;
	RCK=0;
	while(1)
	{
		MatrixLED_ShowColumn(0,0x3C);
		MatrixLED_ShowColumn(1,0x42);
		MatrixLED_ShowColumn(2,0xA9);
		MatrixLED_ShowColumn(3,0x85);
		MatrixLED_ShowColumn(4,0x85);
		MatrixLED_ShowColumn(5,0xA9);
		MatrixLED_ShowColumn(6,0x42);
		MatrixLED_ShowColumn(7,0x3C);
	}
}
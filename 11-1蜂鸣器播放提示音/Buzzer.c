#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h"
sbit Buzzer=P2^5;
//蜂鸣器延时500us函数
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

//蜂鸣器发声 参数为发生时常 ms
void Buzzer_Time(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}
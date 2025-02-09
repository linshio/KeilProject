#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"
unsigned char Hour,Minute,Sec;
void main()
{
	LCD_Init();
	Time0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	//时间格式
	LCD_ShowString(2,1,"  :  :  ");
	//计时器
	while(1)
	{
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Minute,2);
		LCD_ShowNum(2,7,Sec,2);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Minute++;
			if(Minute>=60)
			{
				Minute=0;
				Hour++;
				if(Hour>=24)
				{
					Hour=0;
				}
			}
		}
	}
}
#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>
unsigned char KeyNum,LEDMode;
void main()
{
	//P2附一个初始值 
	P2=0xFE;
	Time0_Init();
	while(1)
	{
		KeyNum=getKeyNumber();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2)
				{
					LEDMode=0;
				}
				
			}
		}
	}
}

//中断函数  是LED灯每秒闪烁一次 1秒等于1000毫秒
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值 TL0拼接TH0的值为64535 与溢出值相差1000us即1ms
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(LEDMode==0)
		{
			P2=_crol_(P2,1);//将p2循环左移1位，溢出时会循环
		}
		if(LEDMode==1)
		{
			P2=_cror_(P2,1);//循环右移
		}
	}
}



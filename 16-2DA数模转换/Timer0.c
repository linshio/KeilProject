#include <REGX52.H>
//100微秒@11.0592MHz 定时器的初始化 100微秒执行一次
void Time0_Init()
{
	//TMOD=0x01;
	TMOD &= 0xF0;		//设置定时器模式 在不改变前四位的情况下将后四位清零
	TMOD |= 0x01;		//设置定时器模式 在不改变前四位的情况下将后四位改为0001
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

//中断函数 具体要执行的内容
//void Timer0_Routine() interrupt 1
//{
//	static unsigned int T0Count;
//	TL0 = 0xA4;		//设置定时初值
//	TH0 = 0xFF;		//设置定时初值
//	T0Count++;
//	if(T0Count>=1000)
//	{
//		T0Count=0;
//		P2_0=~P2_0;
//	}
//}
#include <REGX52.H>
//100微秒@11.0592MHz 定时器的初始化 100微秒执行一次
void Time1_Init()
{
	//TMOD=0x01;
	TMOD &= 0x0F;		//设置定时器模式 在不改变前四位的情况下将后四位清零
	TMOD |= 0x10;		//设置定时器模式 在不改变前四位的情况下将后四位改为0001
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF0标志
	TR1 = 1;		//定时器0开始计时
	ET1=1;
	EA=1;
	PT1=0;
}

//中断函数 具体要执行的内容
//void Timer1_Routine() interrupt 3
//{
//	static unsigned int T1Count;
//	TL1 = 0xA4;		//设置定时初值
//	TH1 = 0xFF;		//设置定时初值
//	T1Count++;
//	if(T1Count>=1000)
//	{
//		T1Count=0;
//		P2_0=~P2_0;
//	}
//}
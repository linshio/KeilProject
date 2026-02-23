#include <REGX52.H>
//1毫秒@11.0592MHz 定时器的初始化 1毫秒执行一次
void Time0_Init()
{
	//TMOD=0x01;
	TMOD &= 0xF0;		//设置定时器模式 在不改变前四位的情况下将后四位清零
	TMOD |= 0x01;		//设置定时器模式 在不改变前四位的情况下将后四位改为0001
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0不计时
}

void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Timer0_GetCounter(void)
{
	return (TH0<<8)|TL0;
}
/**
  * @brief  计时标志位
  * @param  Flag=0停止计时 Flag=1开始计时
  * @retval 
  */
void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;
}
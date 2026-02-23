#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "AT24C02.h"

unsigned char KeyNum,Min,Sec,MiniSec,RunFlag;
void main()
{
	Time0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			RunFlag=!RunFlag;
		}
		if(KeyNum==2)
		{
			Sec=0;Min=0;MiniSec=0;
		}
		if(KeyNum==3)
		{
			AT24C02_WriteByte(0,Min);
			Delay(5);
			AT24C02_WriteByte(1,Sec);
			Delay(5);
			AT24C02_WriteByte(2,MiniSec);
			Delay(5);
		}
		if(KeyNum==4)
		{
			Min=AT24C02_ReadByte(0);
			Sec=AT24C02_ReadByte(1);
			MiniSec=AT24C02_ReadByte(2);
		}
		Nixie_SetBuf(1,Min/10);
		Nixie_SetBuf(2,Min%10);
		Nixie_SetBuf(3,11);
		Nixie_SetBuf(4,Sec/10);
		Nixie_SetBuf(5,Sec%10);
		Nixie_SetBuf(6,11);
		Nixie_SetBuf(7,MiniSec/10);
		Nixie_SetBuf(8,MiniSec%10);
	}
}
//计时中断函数
void Sec_Loop(void)
{
	//计时暂停标志位
	if(RunFlag)
	{
		MiniSec++;
		if(MiniSec>=100)
		{
			MiniSec=0;
			Sec++;
			if(Sec>=60)
			{
				Sec=0;
				Min++;
				if(Min>=60)
					Min=0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	//每隔20ms对键盘按键进行中断检测
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		keyLoop();
	}
	//数码管每隔2ms进行中断检测
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		NixieLoop();
	}
	//计时每10ms给MiniSec加1
	T0Count3++;
	if(T0Count3>=10)
	{
		T0Count3=0;
		Sec_Loop();
	}
}
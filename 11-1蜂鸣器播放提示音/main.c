#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Delay.h"
#include "Buzzer.h"

unsigned char KeyNum;
void main()
{
	Nixie(1,0);
	while(1)
	{
		KeyNum=getKeyNumber();
		if(KeyNum)
		{
			//按下按键松开的时候出发蜂鸣器响声，固定频率
			Buzzer_Time(300);
			Nixie(1,KeyNum);
		}
	}
}
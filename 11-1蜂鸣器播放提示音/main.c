#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Delay.h"
#include "Buzzer.h"

unsigned char KeyNum;
void main()
{
	Nixie(2,0);
	while(1)
	{
		KeyNum=getKeyNumber();
		if(KeyNum)
		{
			Buzzer_Time(300);
			Nixie(2,KeyNum);
		}
	}
}
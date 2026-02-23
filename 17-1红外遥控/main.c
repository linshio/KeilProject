#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "IR.h"
unsigned char Num;
unsigned char Address=0,Command=0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"hello");
	IR_Init();
	while(1)
	{
		if(IR_GetDataFlag()||IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			LCD_ShowHexNum(2,1,Address,2);
			LCD_ShowHexNum(2,5,Command,2);
			if(Command==IR_VOT_MINUS)
			{
				Num--;
			}
			if(Command==IR_VOT_ADD)
			{
				Num++;
			}
			
			LCD_ShowNum(2,10,Num,3);
		}
	}
}

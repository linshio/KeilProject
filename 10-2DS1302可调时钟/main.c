#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Timer0.h"
#include "Key.h"
unsigned char KeyNum,MODE,TimeSetSelect;

void TimeShow()
{
	DS1302_ReadTime();
	LCD_ShowNum(1,1,DS1302_Time[0],2);
	LCD_ShowNum(1,4,DS1302_Time[1],2);
	LCD_ShowNum(1,7,DS1302_Time[2],2);
	LCD_ShowNum(2,1,DS1302_Time[3],2);
	LCD_ShowNum(2,4,DS1302_Time[4],2);
	LCD_ShowNum(2,7,DS1302_Time[5],2);
}

void TimeSet()
{
	if(KeyNum==2)
	{
		TimeSetSelect++;
		TimeSetSelect%=6;
	}
	if(KeyNum==3)
	{
		DS1302_Time[TimeSetSelect]++;
		//合法性校验
		DS1302_Time[0]%=100;
		DS1302_Time[1]%=13;
		DS1302_Time[2]%=32;
		DS1302_Time[3]%=24;
		DS1302_Time[4]%=60;
		DS1302_Time[5]%=60;
	}
	if(KeyNum==4)
	{
		DS1302_Time[TimeSetSelect]--;
		//合法性校验
		DS1302_Time[0]%=100;
		DS1302_Time[1]%=13;
		DS1302_Time[2]%=32;
		DS1302_Time[3]%=24;
		DS1302_Time[4]%=60;
		DS1302_Time[5]%=60;
	}
	
	LCD_ShowNum(1,1,DS1302_Time[0],2);
	LCD_ShowNum(1,4,DS1302_Time[1],2);
	LCD_ShowNum(1,7,DS1302_Time[2],2);
	LCD_ShowNum(2,1,DS1302_Time[3],2);
	LCD_ShowNum(2,4,DS1302_Time[4],2);
	LCD_ShowNum(2,7,DS1302_Time[5],2);
	LCD_ShowNum(2,10,TimeSetSelect,2);
}
void main()
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_SetTime();
	while(1)
	{
		KeyNum = getKeyNumber();
		if(KeyNum==1) 
		{
			MODE=!MODE;
		}
		switch(MODE)
		{
			case 0:TimeShow();break;
			case 1:TimeSet();break;
		}
		
	}
}
#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

int Result = 0;
void main()
{
	LCD_Init();
//	LCD_ShowChar(1,1,'B');
//	LCD_ShowString(1,3,"hello");
//	LCD_ShowNum(1,9,123,3);
//	LCD_ShowSignedNum(1,13,-666,3);
//	LCD_ShowHexNum(2,1,0xDD,2);
//	LCD_ShowBinNum(2,4,0xDD,8);
	while(1)
	{
		Result++;
		Delay(1000);
		LCD_ShowNum(1,1,Result,5);
	}
}
#include <REGX52.H>
#include "LCD1602.h"
#include "MatrixKey.h"
unsigned char keyNum;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey==>");
	while(1)
	{
		keyNum = getPressNumber();
		if(keyNum)
		{
			LCD_ShowSignedNum(2,1,keyNum,2);
		}
	}
}

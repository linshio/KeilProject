#include <REGX52.h>
#include "LCD1602.h"
#include "Key.h"
#include "AT24C02.h"
#include "Delay.h"

unsigned char Data,key;
unsigned int Num;
void main()
{
	
	LCD_Init();
	//默认显示Num数据
	LCD_ShowNum(1,1,Num,5);
	while(1)
	{
		key=getKeyNumber();
		if(key==1)
		{
			Num++;
			LCD_ShowNum(1,1,Num,5);
		}
		if(key==2)
		{
			Num--;
			LCD_ShowNum(1,1,Num,5);
		}
		if(key==3)//写入数据
		{
			//在0号位置上写入Num的低八位数据
			AT24C02_WriteByte(0,Num%256);
			//在1号位置上写入Num的高八位数据
			//往ROM中写入数据后由于其物理特性需要延时5ms
			Delay(5);
			AT24C02_WriteByte(1,Num/256);
			Delay(5);
			//显示反馈后过1s后消失
			LCD_ShowString(2,1,"Write OK");
			Delay(1000);
			LCD_ShowString(2,1,"        ");
		}
		if(key==4)//读取数据
		{
			//读取低八位数据
			Num=AT24C02_ReadByte(0);
			//读取高八位数据
			Num|=AT24C02_ReadByte(1)<<8;
			LCD_ShowNum(1,1,Num,5);
			//显示反馈后过1s后消失
			LCD_ShowString(2,1,"Read OK");
			Delay(1000);
			LCD_ShowString(2,1,"       ");
		}
	}
			
}
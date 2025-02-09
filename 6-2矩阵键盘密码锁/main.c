#include <REGX52.H>
#include "LCD1602.h"
#include "MatrixKey.h"
unsigned char keyNum;
unsigned int password,count;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password==>");
	while(1)
	{
		keyNum = getPressNumber();
		if(keyNum)
		{
			//这里表示1234567890按键有效
			if(keyNum<=10)
			{
				if(count<4)
				{
					password *= 10;
					password += keyNum%10;
					//按下计数
					count++;
				}
				LCD_ShowNum(2,1,password,4);
			}
			//将11按键设施为确认键
			if(keyNum==11)
			{
				//校验密码
				if(password==6666)
				{
					//密码正确
					LCD_ShowString(1,14,"OK ");
					//密码清零 count清零
					password=0;
					count=0;
					//更新密码显示
					LCD_ShowNum(2,1,password,4);
				}
				else
				{
					//密码错误
					LCD_ShowString(1,14,"ERR");
					//密码清零 count清零
					password=0;
					count=0;
					//更新密码显示
					LCD_ShowNum(2,1,password,4);
				}
			}
			//将12按键设置为取消键
			if(keyNum==12)
			{
				//密码清零 count清零
				password=0;
				count=0;
				//更新密码显示
				LCD_ShowNum(2,1,password,4);
			}
			//将13按键设置为退格键
			if(keyNum==13)
			{
				//能退格的条件
				if(count>0 && count <=4)
				{
					password /= 10;
					//计数--
					count--;
					//更新密码显示
					LCD_ShowNum(2,1,password,4);
				}
			}
		}
	}
}

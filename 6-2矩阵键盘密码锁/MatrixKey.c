#include <REGX52.H>
#include "Delay.h"

//先按列扫描，再按行扫描。返回按下的建码
//如果按住不动会停留在此方法中，松开手后会立刻返回keyNumber
unsigned char getPressNumber()
{
	unsigned char keyNumber = 0;
	//第一列
	P1=0xFF;
	P1_3=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		keyNumber = 1;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		keyNumber = 5;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		keyNumber = 9;
	}
	if(P1_4==0)
	{
		Delay(20);
		while(P1_4==0);
		Delay(20);
		keyNumber = 13;
	}
	//第二列
	P1=0xFF;
	P1_2=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		keyNumber = 2;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		keyNumber = 6;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		keyNumber = 10;
	}
	if(P1_4==0)
	{
		Delay(20);
		while(P1_4==0);
		Delay(20);
		keyNumber = 14;
	}
	//第三列
	P1=0xFF;
	P1_1=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		keyNumber = 3;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		keyNumber = 7;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		keyNumber = 11;
	}
	if(P1_4==0)
	{
		Delay(20);
		while(P1_4==0);
		Delay(20);
		keyNumber = 15;
	}
	//第四列
	P1=0xFF;
	P1_0=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		keyNumber = 4;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		keyNumber = 8;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		keyNumber = 12;
	}
	if(P1_4==0)
	{
		Delay(20);
		while(P1_4==0);
		Delay(20);
		keyNumber = 16;
	}
	return keyNumber;
}
#include <REGX52.H>
#include "Delay.h"
unsigned char Nixie_Buf[9]={0,10,10,10,10,10,10,10,10};
unsigned int NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};
//对数码管中的数组进行赋值操作
void Nixie_SetBuf(unsigned char location,number)
{
	Nixie_Buf[location]=number;
}
//将第slot个位置显示number
void Nixie_Scan(unsigned char slot,number){
	//防止串数据
	P0=0x00;
	switch(slot){
		case 1: P2_4=1;P2_3=1;P2_2=1; break;
		case 2: P2_4=1;P2_3=1;P2_2=0; break;
		case 3: P2_4=1;P2_3=0;P2_2=1; break;
		case 4: P2_4=1;P2_3=0;P2_2=0; break;
		case 5: P2_4=0;P2_3=1;P2_2=1; break;
		case 6: P2_4=0;P2_3=1;P2_2=0; break;
		case 7: P2_4=0;P2_3=0;P2_2=1; break;
		case 8: P2_4=0;P2_3=0;P2_2=0; break;
	}
	P0=NixieTable[number];

}
//数码管显示中断延时函数
void NixieLoop(void)
{
	static unsigned char i=1;
	Nixie_Scan(i,Nixie_Buf[i]);
	i++;
	if(i>=9) i=1;
}
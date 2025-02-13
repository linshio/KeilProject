#include <REGX52.H>
#include "Delay.h"
#include "UART.h"


void main()
{
	UartInit();
	while(1)
	{
	
	}
}

void UART_Routine() interrupt 4
{
	//如果是接收的话
	if(RI==1)
	{
		P2=~SBUF;
		//再将输入的数同时进行输出
		UART_SendByte(SBUF);
		//复位
		RI=0;
	}
}
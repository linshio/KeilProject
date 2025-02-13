#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main()
{
	UartInit();
	while(1)
	{
		Sec++;
		UART_SendByte(Sec);
		Delay(1000);
	}
}
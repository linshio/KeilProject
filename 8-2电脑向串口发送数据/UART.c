#include <REGX52.H>

//串口初始化
void UartInit(void)		//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA = 1;
	ES = 1;
}
//发送数据
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	//TI复位
	TI=0;
}

//接收数据
/*
void UART_Routine() interrupt 4
{
	//如果是接收的话
	if(RI==1)
	{
		code...
		//复位
		RI=0;
	}
}
*/

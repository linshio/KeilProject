#include <REGX52.H>

//申明地址变量
sbit I2C_SDA=P2^0;
sbit I2C_SCL=P2^1;

//开始
void I2C_Start(void)	
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
	
}
//结束
void I2C_Stop(void)
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
}
//发送一个字节
void I2C_Sned(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}
//接收一个字节
unsigned char I2C_Receive(void)
{
	unsigned char i,Byte=0x00;
	I2C_SDA=1;
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA) {Byte|=(0x80>>i);}
		I2C_SCL=0;
	}
	return Byte;
	
}
//发送应答
void I2C_SendAck(unsigned char Ackbit)
{
	I2C_SDA=Ackbit;
	I2C_SCL=1;
	I2C_SCL=0;
}
//接收应答
unsigned char I2C_ReceiveAck(void)
{
	unsigned char Ackbit;
	I2C_SDA=1;
	I2C_SCL=1;
	Ackbit=I2C_SDA;
	I2C_SCL=0;
	return Ackbit;
}

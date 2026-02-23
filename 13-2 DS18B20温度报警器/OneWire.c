#include <REGX52.H>


sbit OneWire_DQ=P3^7;
/**
  * @brief  单总线初始化
  * @param  
  * @retval 0表示相应主机，1表示未相应主机
  */
unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	EA=0;
	OneWire_DQ=1;
	OneWire_DQ=0;
	i = 227;while (--i); //延时500us
	OneWire_DQ=1;
	i = 29;while (--i);//延时70us
	AckBit=OneWire_DQ;
	i = 227;while (--i); //延时500us 等待从机操作结束
	EA=1;
	return AckBit;
}

/**
  * @brief  发送1位数据
  * @param  数据
  * @retval 
  */
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	EA=0;
	OneWire_DQ=0;
	i = 3;while (--i);//延时10us
	OneWire_DQ=Bit;
	i = 22;while (--i);//延时50us
	OneWire_DQ=1;
	EA=1;
}

/**
  * @brief  接收1位数据
  * @param  
  * @retval 返回接收的1位数据
  */
unsigned char OneWire_ReceiveBit(void)
{
	unsigned char i,Bit;
	EA=0;
	OneWire_DQ=0;
	i = 2;while (--i);//延时5us
	OneWire_DQ=1;
	i = 2;while (--i);//延时5us
	Bit=OneWire_DQ;
	i = 22;while (--i);//延时50us
	EA=1;
	return Bit;
}

/**
  * @brief  发送一个字节数据
  * @param  发送数据
  * @retval 
  */
void OneWire_SendByte(unsigned char Byte)
{
  unsigned char i;
	for(i=0;i<8;i++)
	{
		OneWire_SendBit(Byte&(0x01<<i));
	}
}

/**
  * @brief  接收一个字节数据
  * @param  
  * @retval 返回数据
  */
unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	for(i=0;i<8;i++)
	{
		if(OneWire_ReceiveBit())
		{
			Byte|=(0x01<<i);
		}
	}
	return Byte;
}





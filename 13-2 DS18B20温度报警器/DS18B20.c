#include <REGX52.H>
#include "OneWire.h"
//SKIP ROM [CCh]
//CONVERT T [44h]
//READ SCRATCHPAD [BEh]

#define DS18B20_SKIP_ROM  				0xCC
#define DS18B20_CONVERT_T  				0x44
#define DS18B20_READ_SCRATCHPAD  	0xBE

/**
  * @brief  温度变换
  * @param  
  * @retval 
  */
void DS18B20_ConverT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

/**
  * @brief  温度读取
  * @param  
  * @retval 温度
  */
float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	//临时变量
	int Temp;
	//温度值
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiveByte();//低8位
	TMSB=OneWire_ReceiveByte();//高8位
	Temp=(TMSB<<8)|TLSB;
	T=Temp/16.0;
	return T;
}

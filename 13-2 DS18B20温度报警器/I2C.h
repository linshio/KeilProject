#ifndef __I2C_H__
#define __I2C_H__
//开始
void I2C_Start(void);
//结束
void I2C_Stop(void);
//发送一个字节
void I2C_Sned(unsigned char Byte);
//接收一个字节
unsigned char I2C_Receive(void);
//发送应答
void I2C_SendAck(unsigned char Ackbit);
//接收应答
unsigned char I2C_ReceiveAck(void);
#endif
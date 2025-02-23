#ifndef __DS1302_H__
#define __DS1302_H__
//声明时间数组
extern unsigned char DS1302_Time[];
//时间初始化
DS1302_Init(void);
//向指定的地址写入数据
DS1302_WriteByte(unsigned char Commond,Data);
//向指定的地址读取数据
DS1302_ReadByte(unsigned char Commond);
//设置初始时间
void DS1302_SetTime(void);
//读取时间
void DS1302_ReadTime(void);
#endif
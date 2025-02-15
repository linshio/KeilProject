#ifndef __METRIXLED_H__
#define __METRIXLED_H__
//矩阵LED初始化参数
void MatrixLED_Init();
//写入74HC595一个字节
void _74HC595_WriteByte(unsigned char Byte);
	//LED点阵屏显示一列数据
//Column需要显示的列 范围0-7
//Data每列需要显示的数据 高位在上，1为亮，0为灭
void MatrixLED_ShowColumn(unsigned char Column,Data);
#endif
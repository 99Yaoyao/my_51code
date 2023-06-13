#ifndef __LCD1602_H__
#define __LCD1602_H__

#include <regx52.h>

#define LCD_EN P2_7 // LCD的使能, 从1至0时（下降沿到来）执行指令
#define LCD_RS P2_6 // 0为写指令， 1为写数据
#define LCD_RW P2_5 // 0为写指令或数据， 1为读取信息
#define LCD_DATA P0 // 向P0输入数据

void LCD1602_WriteCommand(unsigned char command);

void LCD1602_Init(void);

void LCD_ShowChar(unsigned char row, unsigned char col, unsigned char Char);

void LCD_ShowNumber(unsigned char row, unsigned char col, unsigned int Num);

void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);

void LCD_ShowString(unsigned char row, unsigned char col, const unsigned char *str);

#endif

#include "LCD1602.h"
#include "Delay.h"
#include <math.h>

void LCD1602_WriteCommand(unsigned char command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_EN = 1;
	LCD_DATA = command;
	LCD_EN = 0;
	Delay(1);
}

void LCD1602_WriteData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_EN = 1;
	LCD_DATA = Data;
	LCD_EN = 0;
	Delay(1);
}

void LCD1602_Init(void)
{
	Delay(1);
	LCD1602_WriteCommand(0x01); // 清屏
	LCD1602_WriteCommand(0x38); // 设置8位数据线模式，显示两行，
	LCD1602_WriteCommand(0x0C); // 设置显示开，无光标，光标不闪烁
	LCD1602_WriteCommand(0x06); // 设置写入新数据后光标右移，显示屏不移动
	Delay(1);
}

/*
** Function: 设置行列光标在哪打印
*/
void Set_RowandCol(unsigned char row, unsigned char col)
{
	if (col > 16)
		return;
	if (row == 1)
	{
		LCD1602_WriteCommand(0x80 + (col - 1)); // 0x80是因为DB7默认为1，所以最高位固定了，剩下的位置就是0x80+0x00，0x01……
	}
	else if (row == 2)
	{
		LCD1602_WriteCommand(0xC0 + (col - 1)); // 0xC0是因为DB7默认为1，剩下的位置就是0x80+0x40，0x41……，所以是C开头
	}
	else
		return;
}

void LCD_ShowChar(unsigned char row, unsigned char col, char Char)
{
	Set_RowandCol(row, col);
	LCD1602_WriteData(Char);
}

void LCD_ShowString(unsigned char row, unsigned char col, const char *str)
{
	unsigned int i = 0;
	Set_RowandCol(row, col);
	for (i = 0; str[i] != '\0'; i++)
	{
		LCD1602_WriteData(str[i]);
	}
}

int LCD_Pow(int X, int Y)
{
	unsigned char i;
	int Result = 1;
	for (i = 0; i < Y; i++)
	{
		Result *= X;
	}
	return Result;
}

void LCD_ShowNumber(unsigned char row, unsigned char col, unsigned int num)
{
	unsigned int count = 4;
	unsigned char tmp = 0;
	Set_RowandCol(row, col);

	if (num == 0)
	{
		while (count--)
			LCD1602_WriteData('0');
	}
	else
	{
		//        tmp = num;
		//        while (tmp != 0)
		//        {
		//            tmp /= 10;
		//            count++;
		//        }
		for (; count > 0; count--)
		{
			LCD1602_WriteData((num / LCD_Pow(10, count - 1) % 10) + '0');
			// pow函数返回double型，浮点型不能求余，所以得转换类型
			// 假设传入123 ，则有 123 / 100 = 1 % 10 = 1，打印 1
			//               有  123 / 10 = 12 % 10 = 2，打印 2
			//              有   123 / 1 = 123 % 10 = 3，打印 3
			// 不能用pow函数（不知道为何）
		}
	}
}

void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;
	Set_RowandCol(Line, Column);
	for (i = Length; i > 0; i--)
	{
		LCD1602_WriteData(Number / LCD_Pow(10, i - 1) % 10 + '0');
	}
}
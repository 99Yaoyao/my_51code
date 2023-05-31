#include <REGX52.H>

#define LCD_data  P0
sbit LCD_WR = P2^5;
sbit LCD_RS = P2^6;
sbit LCD_EN = P2^7;

/*********************************************************/
void Delay1ms(void)		
{
	unsigned char i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
/**********************************************************/

void send_command_LCD1602(u8 command)//发送指令
{
    LCD_RS = 0;//指令有关
    LCD_WR = 0;//0是写1是读
    LCD_data = command;//发送指令
    LCD_EN = 1;//EN置1后置0表示数据发送
    Delay1ms();
    LCD_EN = 0;
    Delay1ms();
}

void send_data_LCD1602(u8 dat)
{
    LCD_RS = 1;//数据有关
    LCD_WR = 0;//写
    LCD_data = dat;//发送数据
    LCD_EN = 1;//EN置1后置0表示数据发送
    Delay1ms();
    LCD_EN = 0;
    Delay1ms();    
}

void Init_LCD1602(void)//初始化LCD
{
    send_command_LCD1602(0x38);
    send_command_LCD1602(0x0C);
    send_command_LCD1602(0x06);
    send_command_LCD1602(0x01);
}

void set_cursor_LED(u8 row, u8 col)
{
    
}

void show_char(u8 row, u8 col, u8 cha)
{
    if(row == 1)
        send_command_LCD1602(0x80 | (col - 1));
    else if(row == 2)
        send_command_LCD1602(0x80 | (col - 1) + 0x40);
    else 
        
}






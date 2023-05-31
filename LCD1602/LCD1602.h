#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD1602_Init();
void send_command_LCD1602(u8 command);
void send_data_LCD1602(u8 dat);

#endif
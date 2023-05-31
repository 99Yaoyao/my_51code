#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_Init();
void DS1302_WriteByte(u8 command, u8 dat);
u8 DS1302_ReadByte(u8 command);

#endif
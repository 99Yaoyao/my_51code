#include <REGX52.H>

sbit DS_SCLK = P3^6;
sbit DS_IO = P3^4;
sbit DS_CE = P3^5;

u8 Time[] = {23,01,08,19,35,00,7};

void DS1302_Init()
{
    DS_CE = 0;
    DS_SCLK = 0;
}

void DS1302_WriteByte(u8 command, u8 dat)
{
    u8 i = 0;
    DS_CE = 1;
    for(i = 0; i < 8; i++)
    {
        DS_IO = command & (0x01<<i);
        DS_SCLK = 1;
        DS_SCLK = 0;
    }
    for(i = 0; i < 8; i++)
    {
        DS_IO = dat & (0x01<<i);
        DS_SCLK = 1;
        DS_SCLK = 0;
    }
    DS_CE = 0;
}

u8 DS1302_ReadByte(u8 command)
{
    u8 i = 0;
    u8 dat = 0;
    DS_CE = 1;
    for(i = 0; i < 8; i++)
    {
        DS_IO = command & (0x01<<i);
        DS_SCLK = 0;
        DS_SCLK = 1;
    }
    for(i = 0; i<8; i++)
    {
        DS_SCLK = 1;
        DS_SCLK = 0;    
        if(DS_IO)
            dat |= (0x01<<i);
    }
    DS_CE = 0;
    DS_IO = 0;
    return dat;
}

void DS1302_set_time()
{
    u8 i = 0;
    for(i = 0; i<7; i++)
    {
        DS1302_WriteByte((0x80+i), time[i]);//秒
    }
//    DS1302_WriteByte(0x80, time[]);//秒
//    DS1302_WriteByte(0x82, 0x51);//分
//    DS1302_WriteByte(0x84, 0x13);//时
//    
//    DS1302_WriteByte(0x86, 0x08);//日
//    DS1302_WriteByte(0x88, 0x01);//月
//    DS1302_WriteByte(0x8C, 0x23);//年
//    DS1302_WriteByte(0x8A, 0x07);//星期
}

void DS1302_read_time()
{
    
}




#include <REGX52.H>
#include "Delay.h"


sbit RCK = P3^5;//不能用P3_5,P3^5意思是P3的第五位。sbit类似typedef
                //在regx52中P3_5已经被声明地址为0xB5，所以RCK就可以被赋值为P3^5
sbit SCK = P3^6;
sbit SER = P3^4; 
//RCK给1是数据全部发送，SCK给1是向下压一位，SER是保存1bit数据的位
/*
void _74HC595_WriteByte(u8 byte)
{
    u8 count = 0;
    while(byte!=0 || count < 8)
    {
        SER = byte & 0x80;//byte与上0x80，要么是0要么是非0既是1,按位与
        SCK = 1;
        SCK = 0;
        byte = byte << 1;
        count++;
    }
    RCK = 1;
    RCK = 0;
}
*/
/*
void _74HC595_WriteByte1(u8 byte)
{
    u8 i = 0;
    u8 tmp = byte;
    for(;i<8;i++)
    {
        byte = byte<<i;
        SER = byte & 0x80;//byte与上0x80，要么是0要么是非0既是1,按位与
        SCK = 1;
        SCK = 0;
        byte = tmp;
    }
    RCK = 1;
    RCK = 0;
}
*/
void _74HC595_WriteByte2(u8 byte)//控制行的高低电平
{
    u8 i = 0;
    for(;i<8;i++)
    {
        SER = byte & (0x80>>i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void LEDjuzhen_ShowGraph(u8 col, u8 dat)//控制列的高低电平
{
    _74HC595_WriteByte2(dat);
    P0 = ~(0x80>>col);
    Delay(1);
    P0 = 0xFF;
}

int main(void)
{
    SCK = 0;
    RCK = 0;
    
	for(;;)
	{
        LEDjuzhen_ShowGraph(0,0x00);
        LEDjuzhen_ShowGraph(1,0x78);
        LEDjuzhen_ShowGraph(2,0x84);
        LEDjuzhen_ShowGraph(3,0x82);
        LEDjuzhen_ShowGraph(4,0x41);
        LEDjuzhen_ShowGraph(5,0x82);
        LEDjuzhen_ShowGraph(6,0x84);
        LEDjuzhen_ShowGraph(7,0x78);
	}
	return 0;
}
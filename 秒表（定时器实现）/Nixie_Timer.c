#include <REGX52.H>
#include "Delay.h"

u8 ch[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};
u8 buff[9] = {0,10,10,10,10,10,10,10,10};

void set_buff(u8 input, u8 Num)
{
   buff[input] = Num;
}

void nixie(u8 input, u8 Num)
{
    P0 = 0;
    switch(input)
    {
    case 1: P2_4 = 1;P2_3 = 1;P2_2 = 1; break;
    case 2: P2_4 = 1;P2_3 = 1;P2_2 = 0; break;
    case 3: P2_4 = 1;P2_3 = 0;P2_2 = 1; break;
    case 4: P2_4 = 1;P2_3 = 0;P2_2 = 0; break;
    case 5: P2_4 = 0;P2_3 = 1;P2_2 = 1; break;
    case 6: P2_4 = 0;P2_3 = 1;P2_2 = 0; break;
    case 7: P2_4 = 0;P2_3 = 0;P2_2 = 1; break;
    case 8: P2_4 = 0;P2_3 = 0;P2_2 = 0; break;
    }
    P0 = ch[Num];
    //Delay(1);
    
    //P2_4 = 0;P2_3 = 0;P2_2 = 0;有误，不知道谁教我写的
    //Delay(1);
}

void timer_nixie()//用定时器取代delay
{
    static u8 i = 1;
    nixie(i,buff[i]);
    i++;
    if(i>8)
        i = 1;
}









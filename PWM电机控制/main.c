#include <regx52.h>
#include "Timer0.h"
#include "Key.h"
#include "Delay.h"
#include "Nixie.h"

sbit motor = P1 ^ 0;

unsigned char Counter;
unsigned char Compare;
unsigned char Keynum;
unsigned char Speed;

int main(void)
{
    Timer0_Init();

    for (;;)
    {
        Keynum = Key();
        if(Keynum == 1)
        {
            Speed++;
            Speed%=4;
            if(Speed==0){Compare = 0;}
            if(Speed==1){Compare = 50;}
            if(Speed==2){Compare = 75;}
            if(Speed==3){Compare = 100;} 
        }
        Input(1,Speed);
    }
    return 0;
}

void Timer0_Routine() interrupt 1
{
    TL0 = 0xA4;
    TH0 = 0xFF;
    Counter++;
    Counter %= 100;
    if (Counter > Compare)
    {
        motor = 0;
    }
    else
    {
        motor = 1;
    }
}

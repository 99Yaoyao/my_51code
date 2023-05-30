#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
//P2_0定义为东西向绿灯
//P2_1定义为东西向红灯
//P2_2定义为东西向黄灯

//P2_3定义为南北向绿灯
//P2_4定义为南北向红灯
//P2_5定义为南北向黄灯
u8 Count;
u8 YLED;
sfr DXLV = P2;
int main(void)
{
	Timer0_Init();
    DXLV = 0;
    P2_4 = 0;
	for(;;)
	{
        if(Count == 15)
        {
            P2_0 = 1;    
            for(;Count < 20;)
            {              
                P2_2 = ~P2_2;
                Delay(500);
            }
        }
        if(Count == 20)
        {
            P2_2 = 1;
            P2_1 = 0;
            P2_4 = 1;
            P2_3 = 0;
        }
        if(Count == 35)
        {
            P2_3 = 1;
            for(;Count < 40;)
            {
                P2_5 = ~P2_5;
                Delay(500);
            }
            P2_5 = 1;
        }
        if(Count == 40)
        {
            P2_0 = 0;
            P2_1 = 1;
            P2_4 = 0;
            Count = 0;
        }
	}
	return 0;
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
	TL0 = 0x66;				
	TH0 = 0xFC;
    T0Count++;
    if(T0Count==1000)
    {
        Count++;
        T0Count = 0;
    }
}

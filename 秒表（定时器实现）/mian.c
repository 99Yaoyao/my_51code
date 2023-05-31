#include <REGX52.H>
#include "Timer0.h"
#include "Timer_Key.h"
#include "Nixie.h"
#include "Delay.h"
#include "AT24C02.h"
#include "beep.h"
#include "public.h"

u8 KeyNum;
u8 Sec;
u8 Min;
u8 Minisec;
u8 KeyFlag;
int main(void)
{
	Timer0_Init();
	for(;;)
	{
        KeyNum = retmain_key();
        if(KeyNum == 1)
        {
            KeyFlag = ~KeyFlag;
        }
        if(KeyNum == 2)
        {
            Sec = 0;
            Min = 0;
            Minisec = 0;
        }
        if(KeyNum == 3)
        {
            beep_alarm(100,1);
            AT24C02_write(1,Min);
            Delay(5);
            AT24C02_write(2,Sec);
            Delay(5);
            AT24C02_write(3,Minisec);
            Delay(5);
        }
        if(KeyNum == 4)
        {
            Min = AT24C02_read(1);
            Sec = AT24C02_read(2);
            Minisec = AT24C02_read(3);
        }
        set_buff(1,Min/10);
        set_buff(2,Min%10);
        set_buff(3,11);
        set_buff(4,Sec/10);
        set_buff(5,Sec%10);
        set_buff(6,11);
        set_buff(7,Minisec/10);
        set_buff(8,Minisec%10); 
	}
	return 0;
}

void stopwatch()
{
    if(KeyFlag)
    {
        Minisec++;
        if(Minisec>=100)
        {
            Minisec = 0;
            Sec++;
            if(Sec>=100)
            {
                Sec = 0;
                Min++;
                if(Min >= 60)
                {
                    Min = 0;
                }
            }
        }
    }
}

void Timer0_Routine() interrupt 1
{
    static unsigned char T0Count;
    static unsigned char T0Count1;
    static unsigned char T0Count2;
	TL0 = 0x66;				
	TH0 = 0xFC;
    T0Count++;    
    if(T0Count>=20)
    {
        key_timer();
        T0Count = 0;
    }
    T0Count1++;
    if(T0Count1>=2)
    {
        timer_nixie();
        T0Count1 = 0;
    }
    T0Count2++;
    if(T0Count2>=10)
    {
        T0Count2 = 0;
        stopwatch();
    }
}
/*
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		key_timer();	//20ms调用一次按键驱动函数
	}
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		timer_nixie();//2ms调用一次数码管驱动函数
	}
	T0Count3++;
	if(T0Count3>=10)
	{
		T0Count3=0;
		stopwatch();	//10ms调用一次数秒表驱动函数
	}
}
*/

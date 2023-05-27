#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"
#include "Delay.h"

unsigned char Sec=0;
unsigned char Min=47;
unsigned char Hou=21;

int main(void)
{
    LCD_Init();
    Timer0_Init();
    
    LCD_ShowString(1,1,"CLOCK:");
    LCD_ShowChar(2,3,':');
    LCD_ShowChar(2,6,':');    
    for(;;)
    {
        LCD_ShowNum(2,7,Sec,2);
        LCD_ShowNum(2,4,Min,2);
        LCD_ShowNum(2,1,Hou,2);        
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
        T0Count = 0;
        Sec++;
        if(Sec == 60)
        {
            Sec = 0;
            Min++;
            if(Min == 60)
            {
                Min = 0;
                Hou++;
            }
                if(Hou == 24)
                    Hou = 0;
        }
            
    }
}
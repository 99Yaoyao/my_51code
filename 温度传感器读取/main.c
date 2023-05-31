#include <REGX52.H>
#include "LCD1602.h"
#include "wire.h"
#include "DS18B20.h"
#include "Delay.h"
#include "Key_Timer.h"
#include "beep.h"
#include "AT24C02.h"
#include "Timer0.h"
#define unsigned char u8
float Tem,T;
u8 TH;
u8 TL;
char KeyNum;

int main(void)
{
    DS18B20_convertT();//温度提前转换
    LCD_Init();
    Timer0_Init();
    
    LCD_ShowString(1,1,"T:");
    LCD_ShowString(2,1,"TH:");
    LCD_ShowString(2,9,"TL:");
    TH = AT24C02_read(0);
    TL = AT24C02_read(1);
    if(TH > 125 || TL < -50 || TH < TL)//判断24Ｃ02赋给ＴＨＴＬ的值是否合法
    {
        TH = 20;
        TL = 0;
    }
	for(;;)
	{        
        DS18B20_convertT();
        Delay(1000);
        KeyNum = retmain_key();
        Tem = DS18B20_readT();//从18B20读取到的float值赋给Tem
        T = Tem;//Tem是显示在LCD上的，T是真实跟下面THTL做比较的
        if(Tem < 0)
        {
            LCD_ShowChar(1,3,'-');
            Tem = -Tem;//如果是负度，直接在屏幕上显示一个负号并把负float转换为正数
        }
        else
            LCD_ShowChar(1,3,'+');
            
        LCD_ShowNum(1,4,Tem,3);//显示整数部分
        LCD_ShowChar(1,7,'.');
        LCD_ShowNum(1,8,(unsigned long)(Tem*10000)%10000,4);//显示小数部分，
                                                            //直接把float乘为整数再取余
        if(KeyNum)
        {
            if(KeyNum == 1)
                TH++;
            if(KeyNum == 2)
                TH--;
            if(KeyNum == 3)
                TL++;
            if(KeyNum == 4)
                TL--;            
        }     
        LCD_ShowSignedNum(2,4,TH,3);
        LCD_ShowSignedNum(2,12,TL,3);
        AT24C02_write(0,TH);
        Delay(5);
        AT24C02_write(1,TL);
        Delay(5);
        if(Tem > TH)
        {
            LCD_ShowChar(1,16,'H');
            beep_alarm(1000,10);
        }
        if(Tem < TH)
        {
            LCD_ShowChar(1,16,' ');
        }
        if(Tem < TL)
        {
            LCD_ShowChar(1,16,'L');
            beep_alarm(1000,10);
        } 
        if(Tem > TL)
        {
            LCD_ShowChar(1,16,' ');
        }
	}
	return 0;
}

void Timer0_Routine() interrupt 1// 1—wire对时间非常敏感，如果加上中断会经常打断1-wire的通信，
{                                // 所以在1-wire通信的过程中要把定时器先关闭。使用EA=0，EA=1关闭定时器
    static unsigned int T0Count;
	TL0 = 0x66;				
	TH0 = 0xFC;
    T0Count++;
    if(T0Count==20)
    {
        T0Count = 0;
        key_timer();
    }
}











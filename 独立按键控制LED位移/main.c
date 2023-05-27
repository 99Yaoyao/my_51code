#include <REGX52.H>
#include "Delay.h"

int main(void)//只能按一次位移一次还有bug，非常逊
{
    unsigned char LEDNum = 0;//0000 0001,0000 0010,0000 0100....1000 0000
	for (;;)
	{
		if (P3_1 == 0)
		{
            Delay(20);
            while(P3_1 == 0);
            Delay(20);

            P2 = ~(0x01 << LEDNum);
            LEDNum++;
            if(LEDNum == 8)
                LEDNum = 0;
		}
		if (P3_0 == 0)
		{
            Delay(20);       //这三行
            while(P3_0 == 0);//必须
            Delay(20);       //写对

            if(LEDNum == 0)
                LEDNum = 7;
            else
                LEDNum--;
            P2 = ~(0x01 << LEDNum);              
		}

	}
	return 0;
}

int main(void)//非常银杏，按一次就可全自动化流水灯
{
    char i = 0;
    for(;;)
    { 
        if(P3_1 == 0)
        {
            Delay(20);
            while(P3_1 == 0);
            Delay(20);
                
            for(;;)
            {
                P2 = ~(0x01<<i);
                Delay(500);
                if(i==8)
                    i = -1;
                if(P3_0 == 0)
                    break;
                i++;                
            }
                
        }
        if(P3_0 == 0)
        {
            Delay(20);
            while(P3_0 == 0);
            Delay(20);
       
            for(;;)
            {
                P2 = ~(0x01<<i);
                Delay(500);
                if(i == -1)
                    i = 8;       
                if(P3_1 == 0)
                    break;
                i--;
            }
               
        }  
    }
}
















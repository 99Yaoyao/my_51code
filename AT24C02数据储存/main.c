#include <REGX52.H>
#include "key.h"
#include "Delay.h"
#include "LCD1602.h"
#include "AT24C02.h"
u8 KeyNum;
u16 Num; 

int main(void)
{
    /*LCD_Init();
    AT24C02_write(1,255);//1地址写入1byte数据
    AT24C02_write(2,255);//2地址写入1byte数据，可以直接用数字做地址是因为
    Delay(10);           //24C02有256个字节的空间大小，就是256*8=2048bit  
    est = AT24C02_read(1);
    LCD_ShowNum(1,1,est,4);*/
    LCD_Init();
    LCD_ShowNum(1,1,0,5);
	for(;;)
	{
        KeyNum = Key();
        if(KeyNum==1)
        {
            Num++;
            LCD_ShowNum(1,1,Num,5);
        }
        if(KeyNum==2)
        {
            Num--;
            LCD_ShowNum(1,1,Num,5);
        }
        if(KeyNum==3)
        {
            AT24C02_write(1,Num/256);//高八位
            Delay(5);//写入有时间要求，勿忘！！
            AT24C02_write(2,Num%256);//低八位
            Delay(5);
            LCD_ShowNum(1,1,Num,5);
            LCD_ShowString(2,1,"Write OK");
            Delay(1000);
            LCD_ShowString(2,1,"        ");
        }
        if(KeyNum==4)
        {
            Num |= AT24C02_read(1) << 8;//把高八位左移八位（超出范围后数据不会销毁，只是往更高位移）后按位或上Num
            Num |= AT24C02_read(2);//不能直接赋值，也要按位或上低八位，如果这句写在前面就不用或
            LCD_ShowNum(1,1,Num,5);
            LCD_ShowString(2,1,"Read OK");
            Delay(1000);
            LCD_ShowString(2,1,"       ");
        }
	}
	return 0;
}
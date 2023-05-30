#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"

u8 Sec;
u8 Min;
u8 Hour;
u8 Day;
u8 Mon;
u8 Year;
u8 days;

int main(void)
{
	LCD_Init();
    DS1302_Init();
    
    LCD_ShowString(1,1,"TIME:20");
    //DS1302_WriteByte(0x8E, 0x00);

	for(;;)
	{
        Sec = DS1302_ReadByte(0x81);
        Min = DS1302_ReadByte(0x83);
        Hour = DS1302_ReadByte(0x85);
        Day = DS1302_ReadByte(0x87);
        Mon = DS1302_ReadByte(0x89);
        Year = DS1302_ReadByte(0x8D);
        days = DS1302_ReadByte(0x8B);
        
        LCD_ShowNum(2,13,Sec/16*10+Sec%16,2);
        LCD_ShowChar(2,12,':');
        LCD_ShowNum(2,10,Min/16*10+Min%16,2);
        LCD_ShowChar(2,9,':');
        LCD_ShowNum(2,7,Hour/16*10+Hour%16,2);
        
        LCD_ShowNum(1,14,Day/16*10+Day%16,2);
        LCD_ShowChar(1,13,'/');
        LCD_ShowNum(1,11,Mon/16*10+Mon%16,2);
        LCD_ShowChar(1,10,'/');
        LCD_ShowNum(1,8,Year/16*10+Year%16,2);
        //Delay(1000);
        LCD_ShowNum(2,1,days/16*10+days%16,2);
	}
	return 0;
}
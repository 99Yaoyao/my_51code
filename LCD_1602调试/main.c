#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"

int main()
{
    LCD_Init();
    LCD_ShowChar(1,1,'A');
    LCD_ShowString(2,1,"hello world!");
    LCD_ShowNum(1,3,6,1);
    LCD_ShowSignedNum(1,5,-86,2);
    LCD_ShowHexNum(1,9,0x3D,2);
    LCD_ShowBinNum(1,12,0xAA,4);

    for(;;);
    return 0;
}
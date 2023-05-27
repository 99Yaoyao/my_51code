#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"



int main(void)
{
    u16 tmp = 0;//接收矩阵键盘函数返回的值
    LCD_Init();  
    LCD_ShowString(1,1,"Enter your PIN.");
    for(;;)
    { 
        tmp = MatrixKey();
        if(tmp)
            LCD_ShowNum(2,1,tmp,2);
    }
    return 0;
}









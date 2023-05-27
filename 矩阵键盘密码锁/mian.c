#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"



int main(void)
{
    u16 KeyNum = 0;//接收矩阵键盘函数返回的值
    u16 Password = 0;
    u16 Count = 0;
    LCD_Init();
    LCD_ShowString(1,1,"Enter your PIN:");
    for(;;)
    { 
        KeyNum = MatrixKey();
        if(KeyNum != 0 && KeyNum <= 10)//对键盘输入检索，如果超出s10则不进入语句
        {
            if(Count < 4)//限制输入，最多只能输入四次数字
            {
                Password *= 10;//使数字左移一位
                Password += KeyNum % 10;//使数字
            }
            Count++;
        }
        else if(KeyNum == 11)
            Password = 0;
        LCD_ShowNum(2,1,Password,4);
        
    }
    return 0;
}









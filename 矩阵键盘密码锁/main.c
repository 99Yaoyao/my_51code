#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"



int main(void)
{
    u16 KeyNum = 0;//接收返回的键盘值
    u16 Password = 0;
    u16 Count = 0;
    LCD_Init();
    LCD_ShowString(1,1,"PIN:");
    for(;;)
    { 
        KeyNum = MatrixKey();
        if(KeyNum != 0 && KeyNum <= 10)//键盘值不能超过10且不能为0
        {
            if(Count < 4)//只能输入四位密码
            {
                Password *= 10;//密码左移一位
                Password += KeyNum % 10;//下一位密码输入，10作为0，10模10就是0
                Count++;
            }
        }
        if(KeyNum == 11)//s11作为确认键
        {
            if(Password == 1234)//判断密码是否正确
            {
                LCD_ShowString(2,1,"SUCC");
                Delay(3000);
                break;           //如果密码正确，跳出for循环（来到return 0处，程序结束） 
            }
            else
            {
                LCD_ShowString(2,1,"ERR");
                Password = 0;    //如果输入错误，密码与计数器都清零，重新输入
                Count = 0;
            }
                
        }
        if(KeyNum == 12)//s12作为删除键
        {
            if(Count > 0)
            {
                Password /= 10;//密码删除一位
                Count--; 
            }               
        }
        
        LCD_ShowNum(1,5,Password,4);//更新显示        
    }
    return 0;
}









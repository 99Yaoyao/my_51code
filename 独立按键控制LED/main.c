#include <REGX52.H>
#include "Delay.h"
//int main(void)
//{
//    //P2 = 0xFE;//直接操作整个寄存器
//    for (;;)
//    {
//        if (P3_1 == 0)
//            P2_0 = 0;//单独操作位寄存器
//        else
//            P2_0 = 1;
//    }
//    return 0;
//}

//新写法
int main(void)
{
    //P2 = 0xFE;//直接操作整个寄存器
    for (;;)
    {
        if (P3_1 == 0)
        {
            Delay(20);
            while(P3_1 == 0);
            P2_0 = ~P2_0;//单独操作位寄存器
            //Delay(20);
            while(P3_1 == 1);
            Delay(20);
        }
            
    }
    return 0;
}
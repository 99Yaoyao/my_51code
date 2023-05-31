#include <REGX52.H>
#include "Delay.h"
#include "public.h"
/*
unsigned char key()//获取独立按键键码
{
    unsigned char KeyNumber = 0;
    
    if(P3_1 == 0){Delay(20); while(P3_1 == 0); Delay(20); KeyNumber = 1;}
    if(P3_0 == 0){Delay(20); while(P3_0 == 0); Delay(20); KeyNumber = 2;}
    if(P3_2 == 0){Delay(20); while(P3_2 == 0); Delay(20); KeyNumber = 3;}
    if(P3_3 == 0){Delay(20); while(P3_3 == 0); Delay(20); KeyNumber = 4;}
    
    return KeyNumber;
}
*/
u8 Global_Key;
unsigned char not_delay_key()//获取独立按键键码
{
    unsigned char KeyNumber = 0;
    
    if(P3_1 == 0){KeyNumber = 1;}
    if(P3_0 == 0){KeyNumber = 2;}
    if(P3_2 == 0){KeyNumber = 3;}
    if(P3_3 == 0){KeyNumber = 4;}
    
    return KeyNumber;
}
void key_timer()//定时器在这个文件的分身
{
    static u8 last;
    static u8 now;
    last = now;
    now = not_delay_key();
    if(last == 1 && now == 0)
        Global_Key = 1;
    if(last == 2 && now == 0)
        Global_Key = 2;
    if(last == 3 && now == 0)
        Global_Key = 3;
    if(last == 4 && now == 0)
        Global_Key = 4;
}

u8 retmain_key()//返回主函数的值
{
    u8 tmp = 0;
    tmp = Global_Key;
    Global_Key = 0;
    return tmp;
}







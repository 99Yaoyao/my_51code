#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

int main(void)
{
    UART_Init();
    //UART_SendByte(0xFF);     
    for(;;)
    {
//        if(P3_1 == 0)//使用独立按键发送会同时发送00，原因不明
//        {
//            Delay(20);
//            while(P3_1 == 0);
//            Delay(20);
            UART_SendByte(Sec); 
            Sec++;
            Delay(100);
//        }            
    }
    return 0;
}








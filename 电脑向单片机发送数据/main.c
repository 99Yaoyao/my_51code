#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

int main(void)
{
    UART_Init();
    for(;;)
    {
         
    }
    return 0;
}


void UART_Routine() interrupt 4
{
    if(RI == 1)
    {
        P2 = ~SBUF;
        UART_SendByte(SBUF);
        RI = 0;
    }
}





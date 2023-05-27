#include <REGX52.H>
#include "delay.h"

unsigned char i;

int main(void)
{
    for (;;)
    {
        for (i = 0; i < 8; i++)
        {
            P2 = ~((0x01) << i);
            delay(200);
        }
    }
}

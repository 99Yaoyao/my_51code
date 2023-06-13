#include "Delay.h"

void Delay(unsigned int xms) // 延时任意毫秒
{
    unsigned int k = 0;
    unsigned char i, j;
    for (k = 0; k < xms; k++)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}

void Delay10us(unsigned int xus) // 延时任意10微秒
{
    unsigned char i;
    while (xus--)
    {
        i = 247;
        while (--i)
            ;
    }
}
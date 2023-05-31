#include <REGX52.H>

sbit LED = P2 ^ 0;

void delay(unsigned char i)
{
    while (i--)
        ;
}

int main(void)
{
    unsigned char i = 0;
    unsigned char j = 0;
    for (;;)
    {
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 20; j++)
            {
                LED = 0;
                delay(i);
                LED = 1;
                delay(100 - i);
            }
        }
        for (i = 100; i > 0; i--)
        {
            for (j = 0; j < 20; j++)
            {
                LED = 0;
                delay(i);
                LED = 1;
                delay(100 - i);
            }
        }
    }

    return 0;
}
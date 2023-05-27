#include <REGX52.H>

void delay(unsigned int ms)		//@12.000MHz
{
    unsigned int k;
	unsigned char i, j;
    for(k=0; k<ms; k++)
    {
        i = 12;
        j = 169;
        do
        {
            while (--j);
        } while (--i);
    }
}

int main(void)
{
	for (;;)
	{
		if (P3_1 == 0)
		{
			delay(20);
			P2 -= 1;
			delay(20);
		}
        if(P2 == 0)
        {
            P2 = 0xFF;
        }
	}
	return 0;
}
#include <REGX52.H>

void delay(u16 ms)		//@12.000MHz
{
    u16 k = 0;
	unsigned char i, j;
    for(; k<ms; k++)
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
            //while(P3_1 == 0);
			
			P2_0 = ~P2_0;
            delay(20);
		}
        
	}
	return 0;
}
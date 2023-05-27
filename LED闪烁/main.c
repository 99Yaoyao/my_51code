#include <REGX52.h>
#include <INTRINS.h>

void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


int main(void)
{
    for(;;)
    {
        P2_0 = 0;
        Delay500ms();
        P2_0 = 1;
        Delay500ms();
    }
    return 0;
}

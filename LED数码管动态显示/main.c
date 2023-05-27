#include <REGX52.H>
#include "Delay.h"
#include "Nixie_Tube.h"

int main(void)
{  
	for (;;)
	{
        Input(6,1);
        Input(7,0);
        Input(8,0);
	}
	return 0;
}
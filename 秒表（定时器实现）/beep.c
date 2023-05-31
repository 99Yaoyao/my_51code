#include "beep.h"
#include "Delay.h"
#include <REGX52.H>
#include "public.h"
sbit BEEP=P2^5;

void beep_alarm(unsigned int time,unsigned int fre)
{
	while(time--)
	{
		BEEP=!BEEP;
		Delay(fre);	
	}		
}
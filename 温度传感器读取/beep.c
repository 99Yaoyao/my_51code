#include "Delay.h"
#include <REGX52.H>

sbit BEEP=P2^5;
/*******************************************************************************
* �� �� ��       : beep_alarm
* ��������		 : ��������������
* ��    ��       : time����������ʱ��
				   fre������Ƶ��
* ��    ��    	 : ��
*******************************************************************************/
void beep_alarm(unsigned int time,unsigned int fre)
{
	while(time--)
	{
		BEEP=!BEEP;
		delay_10us(fre);	
	}		
}
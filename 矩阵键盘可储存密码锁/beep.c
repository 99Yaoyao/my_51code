#include "beep.h"
#include <REGX52.H>
sbit BEEP = P2 ^ 5;
/*******************************************************************************
* 函 数 名       : beep_alarm
* 函数功能		 : 蜂鸣器报警函数
* 输    入       : time：报警持续时间
				   fre：报警频率
* 输    出    	 : 无
*******************************************************************************/

void delay_10us(unsigned int ten_us)
{
	while(ten_us--);	
}

void beep_alarm(unsigned int time, unsigned int fre)
{
	while (time--)
	{
		BEEP = !BEEP;
		delay_10us(fre);
	}
}
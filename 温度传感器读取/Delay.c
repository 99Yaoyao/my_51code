#include "Delay.h"

void Delay(unsigned int xms)//延时任意毫秒
{
    unsigned int k = 0;
    unsigned char i, j;
    for(k = 0; k <xms; k++)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}
/*
void Delay_us(unsigned int xus)//延时任意个10微秒,失败，因为时间太短
{
	unsigned char i;
    unsigned char j;
	for(j = 0; j < xus; j++)
    {
        i = 247;
        while (--i);
    }
}*/

/*******************************************************************************
* º¯ Êý Ãû       : delay_10us
* º¯Êý¹¦ÄÜ		 : ÑÓÊ±º¯Êý£¬ten_us=1Ê±£¬´óÔ¼ÑÓÊ±10us
* Êä    Èë       : ten_us
* Êä    ³ö    	 : ÎÞ
*******************************************************************************/
void delay_10us(unsigned int ten_us)
{
	while(ten_us--);	
}
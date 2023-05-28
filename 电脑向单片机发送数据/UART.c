#include <REGX52.H>

void UART_Init()        //4800bps@11.0592MHz
{
    SCON = 0x50;        //等待电脑发送数据触发中断，打开REN
    PCON &= 0x7F;		//波特率不倍速,11.0592没有误差不用倍速
    
    TMOD &= 0x0F;       //设置定时器模式,清除定时器1模式位
	TMOD |= 0x20;	    //设置定时器模式，设置定时器1为8位自动重装模式
    TL1 = 0xFA;			//设置定时初始值
	TH1 = 0xFA;			//设置定时重载值
	ET1 = 0;            //禁止定时器中断
	TR1 = 1;			//定时器1开始计时  
    EA = 1;
    ES = 1;
}

void UART_SendByte(unsigned char byte)//发送一字节数据到电脑
{
    SBUF = byte;
    while(TI == 0);
    TI = 0;
}

/*//串口中断函数模板
void UART_Routine() interrupt 4
{
    if(RI == 1)
    {
    
        RI = 0;
    }
}
*/






#include <REGX52.H>

void Timer0_Init()//对定时器0初始化，1毫秒@11.0592MHZ
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
    ET0 = 1;
    EA = 1;
    PT0 = 0;

//    //TMOD = 0x01;这种方法会改变高四位原来的值
//    TMOD &= 0xF0;//这种方法对高四位与1（不变），对低四位与0（清零） 
//    TMOD |= 0x01;//低四位0000或0001就是0001
//    TF0 = 0;
//    TR0 = 1; 
//    TH0 = 64535 / 256;计数单元，来一次脉冲+1，一次脉冲时间为1us
//    TL0 = 64535 % 256;高八位与低八位放与65535差一千的64535
}

/*//定时1s的模板,不易模块化
void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
	TL0 = 0x66;				
	TH0 = 0xFC;
    T0Count++;
    if(T0Count==1000)
    {
        T0Count = 0;
    }
}
*/










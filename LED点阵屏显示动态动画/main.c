//#include <REGX52.H>
//#include "Delay.h"
//#include "LEDMatrix.h"
//#include "Timer.h"

//u8 code  ch[] = {
//    0,0,0,0,0,0,0,0,
//    0xFF,0x10,0x20,0x20,0x1F,0x00,0x1E,0x35,
//    0x45,0x45,0x25,0x18,0x00,0x7E,0x01,0x02,
//    0x7E,0x01,0x06,0x00,0x7E,0x81,0x81,0x81,
//    0x7E,0x00,0x00,0x00,0x7D,0x00,0x00,0x00,
//    0,0,0,0,0,0,0,0,
//};

//u8 offset = 0;
//int main(void)//显示流动字幕
//{
//    u8 i = 0;
//    LEDMatrix_Init();
//    Timer0_Init();
//	for(;;)
//	{
//        for(i = 0;i<8;i++)
//        {
//            LEDjuzhen_ShowGraph(i,ch[i+offset]);
//        }
//	}
//	return 0;
//}

//void Timer0_Routine() interrupt 1
//{
//    static unsigned int T0Count;
//	TL0 = 0x66;				
//	TH0 = 0xFC;
//    T0Count++;
//    if(T0Count==100)
//    {
//        offset++;
//        if(offset == 40)
//            offset = 0;
//        T0Count = 0;
//    }
//}





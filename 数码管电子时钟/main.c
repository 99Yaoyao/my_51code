#include "public.h"
#include "key.h"
#include "beep.h"
#include "smg.h"
#include "time.h"


void main()
{	
	u8 key=0;
	u8 time_buf[8];
	u8 time_flag=0;
	time0_init();
    
	for(;;)
	{
		key=key_scan(0);
		if(key==KEY1_PRESS)
		{
			time_flag=!time_flag;
			beep_alarm(1000,10);
		}	
		else if(key==KEY2_PRESS)
		{
			time0_stop();
			time_flag=0;
			gmin=0;
			gsec=0;
			gmsec=0;
			beep_alarm(1000,10);
		}
		if(time_flag)
			time0_start();//开始计时
		else
			time0_stop();//停止计时
            
		time_buf[0]=gsmg_code[ghoure/10];
		time_buf[1]=gsmg_code[ghoure%10];//小时
		time_buf[3]=gsmg_code[gmin/10];
		time_buf[4]=gsmg_code[gmin%10];//分
		time_buf[2]=0x40;//-
		time_buf[6]=gsmg_code[gsec/10];
		time_buf[7]=gsmg_code[gsec%10];//秒
		time_buf[5]=0x40;//-
		//time_buf[6]=gsmg_code[gmsec/10];
		//time_buf[7]=gsmg_code[gmsec%10];//毫秒
		smg_display(time_buf,1);//显示
        
	}
}

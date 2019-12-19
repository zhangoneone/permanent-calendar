 /*利用硬件定时，获取时间并放到数组中*/
#include"END.h"
sbit p36=P3^6;
uint hour,min,sec;
void timer0_init(){		 //定时器T0初始化
   	TMOD=0x61;
	TH0=0x03c;
	TL0=0x0b0;
	TH1=0x0f6;
	TL1=0x0f6;
	TR0=1;
	TR1=1;

	ET0=1;
	ET1=1;
	EA=1;

}
void Handle() //时间处理、获取函数
{
{
   if(sec==60)
    {
      sec=0;
      min++;
      if(min==60)
      {
	    min=0;
        hour++;
      if(hour==24)
       hour=0;
	  }
    }
}
dis1[11]=sec%10+0x30; //将得到的时间数值转换成ascll码让1602识别
dis1[10]=sec/10+0x30;

dis1[8]=min%10+0x30;
dis1[7]=min/10+0x30;

dis1[5]=hour%10+0x30;
dis1[4]=hour/10+0x30;
}  
void t0() interrupt 1//计数器0内部定时65636机器周期中断一次使p36（50ms变反一次,100ms一个周期)

{	
	TF0=0;
	TH0=0x03c;
	TL0=0x0b0;
	p36=~p36;
}
void t1() interrupt 3//定时器1外部计数，记满10个外部脉冲计数器加1，并输出（1秒加1）（P3.6?P3.5）
{	
	
	TF1=0;
	sec++;
}
#include <REGX51.H>
#include"Timer0.h"
#include"Delay.h"
#include"shuzi.h"

unsigned char ledmod[]={0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f};
sbit L0=P2^0;
sbit L1=P2^1;
sbit green_we=P2^2;
sbit yellow_we=P2^3;
sbit red_we=P2^4;
sbit green_ns=P2^5;
sbit yellow_ns=P2^6;
sbit red_ns=P2^7;
unsigned int i=0;

void display(unsigned int x)
{
	L0=1;
	L1=0;
	P1=ledmod[x];
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count0,count1;
	TH0=0xFC;
	TL0=0x18;
	count0++;
	count1++;
	if(count0==1000)		//1s
	{
		count0=0;
		for(i=0;i<10;i++)
		{display(i);Delay(1000);}
	}
	if(count1==1000)		//10s
	{
		count1=0;
		red_we=1;
		green_we=0;
		for(i=0;i<7;i++)
			{display(i);Delay(1000);}
		green_we=1;
		yellow_we=0;display(7);
		Delay(1000);
		yellow_we=1;display(8);
		Delay(1000);
		yellow_we=0;display(9);
		Delay(1000);
		yellow_we=1;			//20s
			while(1)
			{
				red_we=0;
				red_ns=1;
				green_ns=0;
				for(i=0;i<7;i++)
					{display(i);Delay(1000);}
				green_ns=1;
				yellow_ns=0;display(7);
				Delay(1000);
				yellow_ns=1;display(8);
				Delay(1000);
				yellow_ns=0;display(9);
				Delay(1000);
				yellow_ns=1;
					break;				//30s
			}
	}
}



void main()
{ 
	
	Timer0Init();
	while(1)
	{
		red_we=0;
		red_ns=0;
		shuzi(10);
	}
}
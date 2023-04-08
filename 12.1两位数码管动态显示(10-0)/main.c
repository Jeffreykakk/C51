#include <REGX51.H>
#include"Timer0.h"
#include"Delay.h"
#include"shuzi.h"

unsigned char ledmod[]={0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f};
sbit L0=P2^0;
sbit L1=P2^1;
unsigned int i=0;

void display(unsigned int x)
{
	L0=1;
	L1=0;
	P1=ledmod[x];
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count;
	TH0=0xFC;
	TL0=0x18;
	count++;
	if(count==1000)
	{
		count=0;
		for(i=0;i<10;i++)
		{display(i);Delay(1000);}
	}
}



void main()
{
	Timer0Init();
	while(1)
	{
		shuzi(10);
	}
}






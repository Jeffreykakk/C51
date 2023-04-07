#include <REGX51.H>
#include"Delay.h"
#include"display.h"
#include"place.h"
#include"play.h"
#include"Timer0.h"
#include"Key.h"
#include<INTRINS.H>

int i=0,num=0;
void Timer0_Routine() interrupt 1
{
	static unsigned int count;
	TH0=0xFC;
	TL0=0x18;
	count++;
	if(count==1000)
	{
		count=0;
	  num++;
	}
}

void main()
{
	Timer0Init();
	while(1)
	{
		if(num==10)
			num=0;
		display(num);
	}
}
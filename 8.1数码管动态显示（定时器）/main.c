#include <REGX51.H>
#include"Delay.h"
#include"display.h"
#include"place.h"
#include"play.h"
#include"Timer0.h"
#include"Key.h"
#include<INTRINS.H>

unsigned char num1=0;num2=0;
void Timer0_Routine() interrupt 1
{
	static unsigned int count1,count2;
	TH0=0xFC;
	TL0=0x18;
	count1++;
	count2++;
	if(count1==1000)
	{
		count1=0;
		num1++;
	}
	if(count2==10000)
	{
		count2=0;
		num2++;
	}
}

void main()
{
	Timer0Init();
	while(1)
	{
		if(num1==10) num1=0;
		if(num2==8) num2=0;
		place(num2);
		display(num1);
	}
}
#include <REGX51.H>

void initcounter1(unsigned int x)
{
	TMOD=0x06;
	TH0=256-x;
	TL0=256-x;
	ET0=1;
	EA=1;
	TR0=1;
}

// void counter_isr() interrupt 1
//{
//	
//}
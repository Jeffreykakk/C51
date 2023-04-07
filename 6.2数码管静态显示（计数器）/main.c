#include <REGX51.H>
#include"display.h"
#include<INTRINS.H>
#include"initcounter1.h"

unsigned char num=0;
void counter_isr() interrupt 1
{
	num++;
	if(num==10)
		num=0;
}


void main()
{
	initcounter1(2);
	while(1)
	{
		display(num);
	}
}
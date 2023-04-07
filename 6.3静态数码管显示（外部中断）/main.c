#include <REGX51.H>
#include"Delay.h"
#include"display.h"
#include"place.h"
#include"play.h"
#include"Timer0.h"
#include"Key.h"
#include<INTRINS.H>
#include"initcounter1.h"
#include"initex0.h"

unsigned char num=0;

void ex_isr() interrupt 0
{
	num++;
}

void main()
{
	while(1)
	{
		initex0();
		if(num==10)
			num=0;
		display(num);
	}
}

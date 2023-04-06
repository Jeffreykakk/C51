#include <REGX51.H>
#include"display.h"
#include"Delay.h"

void play()
{
	int i=0;
	for(i=0;i<10;i++)
	{
		display(i);
		Delay(500);
	}
}
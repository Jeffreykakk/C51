#include <REGX51.H>
#include"Delay.h"

unsigned char Key()
{
	unsigned char KeyNumber=99;
	
	if(P1_0==0) {Delay(20);while(P1_0==0);Delay(20);KeyNumber=0;}
	if(P1_1==0) {Delay(20);while(P1_1==0);Delay(20);KeyNumber=1;}
	if(P1_2==0) {Delay(20);while(P1_2==0);Delay(20);KeyNumber=2;}
	if(P1_3==0) {Delay(20);while(P1_3==0);Delay(20);KeyNumber=3;}
	
	return KeyNumber;
}
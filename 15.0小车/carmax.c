#include <REGX51.H>
sbit IN1=P2^1;
sbit EN1=P2^2;
sbit IN2=P2^3;
sbit IN3=P2^4;
sbit EN2=P2^5;
sbit IN4=P2^6;	
void carmax()
{
	EN1=1;
	EN2=1;
	IN1=1;
	IN2=0;
  IN3=1;
  IN4=0;
}


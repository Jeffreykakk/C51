#include <REGX51.H>
#include"shuzi.h"

unsigned char duanma[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
sbit L1=P2^1;
sbit L0=P2^0;

void delay1()
{
	unsigned int i,j;
	for(i=0;i<100;i++);
	for(j=0;j<10;j++);
}

void shuzi(unsigned int x)
{
		P0=0x00;
		L1=0;
		L0=1;
		P0=duanma[x%10];
		delay1();
			
		L1=1;
		L0=0;
		P0=duanma[x/10];
		delay1();
}
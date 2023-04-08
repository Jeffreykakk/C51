#include <REGX51.H>
#include"display.h"

unsigned char key=99;
void delay(unsigned int n)
{
	unsigned int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}


void keyscan()
{	
	unsigned char temp0=0,temp1=0,temp=0;
	P1=0xf0;
	if(P1!=0xf0)
	{
		delay(20);
		temp0=P1;
		P1=0x0f;
		if(P1!=0x0f)
		{
			temp1=P1;
		}
	}
	temp=temp0+temp1;
	switch(temp)
	{
		case 0xee: key=0;break;
		case 0xde: key=1;break;
		case 0xbe: key=2;break;
		case 0x7e: key=3;break;
		case 0xed: key=4;break;
		case 0xdd: key=5;break;
		case 0xbd: key=6;break;
		case 0x7d: key=7;break;
		case 0xeb: key=8;break;
		case 0xdb: key=9;break;
		case 0xbb: key=10;break;
		case 0x7b: key=11;break;
		case 0xe7: key=12;break;
		case 0xd7: key=13;break;
		case 0xb7: key=14;break;
		case 0x77: key=15;break;
	}
}

void main()
{
	
	while(1)
	{
		keyscan();
		display(key);
	}
}
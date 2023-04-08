#include <REGX51.H>
#include<INTRINS.H>

unsigned char recdat=0,flag=0;

void senddat()
{
	SBUF=recdat;
	while(!TI);
	TI=0;
}

void initscon()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=256-3;
	TL1=256-3;
	ES=1;
	EA=1;
	TR1=1;
}

void main()
{
	initscon();
	while(1)
	{
		if(flag==1)
		{
			senddat();
			flag=0;
		}
	}
}

void scon_isr() interrupt 4
{
	recdat=SBUF;
	RI=0;
	flag=1;
}
	
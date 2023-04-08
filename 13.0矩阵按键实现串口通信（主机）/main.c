#include <REGX51.H>


void senddata();
void delay(unsigned int n);
void keyscan();
void display(unsigned int x);
void Usart_Init();


unsigned char key=99;
unsigned char ch1[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char time;

void main()
{
	Usart_Init();
	while(1)	
	{
		keyscan();
		display(key);
	}
}



void display(unsigned int x)
{
	P2=ch1[x];
}

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
		case 0xee: key=0;senddata();break;
		case 0xde: key=1;senddata();break;
		case 0xbe: key=2;senddata();break;
		case 0x7e: key=3;senddata();break;
		case 0xed: key=4;senddata();break;
		case 0xdd: key=5;senddata();break;
		case 0xbd: key=6;senddata();break;
		case 0x7d: key=7;senddata();break;
		case 0xeb: key=8;senddata();break;
		case 0xdb: key=9;senddata();break;
	}
}

void senddata()
{
    SBUF=key;      
    while(!TI);      
    TI=0;            
}
 

void Usart_Init()
{
	SCON=0x50;
	TMOD=0x20;
	PCON=0x00;
	TH1=0xf3;
	TL1=0xf3;
	ES=1;
	EA=1;
	TR1=1;
}



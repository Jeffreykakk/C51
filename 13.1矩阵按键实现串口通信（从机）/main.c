#include <REGX51.H>


void Uart_init();
void place(unsigned int x);
void show(unsigned int x);
void Delay(unsigned int xms);
void keyscan();

//void Timer0Init(void);
//void play();

unsigned char receivedata=99;
unsigned char key=99,num=98,i=0;

void main()
{
	Uart_init(); 
	while(1)
	{
		keyscan();
		place(6);
		show(0);
		Delay(1);
		place(7);
		show(key);
		Delay(1);
		place(0);
		show(0);
		Delay(1);
		place(1);
		show(num);
		Delay(1);
		if(num==key)
			while(1)
			{
				P2=0xff;
				P0=0x88;
			}
		if(i==18)
			while(1)
			{
				P2=0xff;
				P0=0x8e;
			}
	}
}


void Uart_init() 
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


void Usart() interrupt 4
{
	receivedata=SBUF; 
	RI=0;
	switch(receivedata)
	{
		case 0:	num=0; break;
		case 1:	num=1; break;
		case 2:	num=2; break;
		case 3:	num=3; break;
		case 4:	num=4; break;
		case 5:	num=5; break;
		case 6:	num=6; break;
		case 7:	num=7; break;
		case 8: num=8; break;
		case 9: num=9; break;
	}       
	 
}


unsigned char ch2[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void place(unsigned int x)
{
	P2=ch2[x];
}


unsigned char ch1[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void show(unsigned int x)
{
	P0=ch1[x];
}

void Delay(unsigned int xms)		
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
	
}

void keyscan()
{	
	unsigned char temp0=0,temp1=0,temp=0;
	P1=0xf0;
	if(P1!=0xf0)
	{
		Delay(20);
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
		case 0xee: key=0;i++;break;
		case 0xde: key=1;i++;break;
		case 0xbe: key=2;i++;break;
		case 0x7e: key=3;i++;break;
		case 0xed: key=4;i++;break;
		case 0xdd: key=5;i++;break;
		case 0xbd: key=6;i++;break;
		case 0x7d: key=7;i++;break;
		case 0xeb: key=8;i++;break;
		case 0xdb: key=9;i++;break;
	}
}




//unsigned char time=9;
//void play()
//{
//	while(1)
//	{
//		place(3);
//		show(0);
//		Delay(1);
//		place(4);
//		show(time);
//		Delay(1);
//	}
//}



//void Timer0Init(void)
//{
//	TMOD=TMOD&0XF0; 
//	TMOD=TMOD|0X01;
//	TF0=0;
//	TR0=1;
//	TH0=0xFC;
//	TL0=0x18;
//	ET0=1;
//	EA=1;
//	PT0=0;
//}



//void Timer0_Routine() interrupt 1
//{
//	static unsigned int count;
//	TH0=0xFC;
//	TL0=0x18;
//	count++;
//	if(count==1000)
//	{
//		count=0;
//		time--;
//		if(time==0)
//		{
//			while(1)
//			{
//				P2=0xff;
//				P0=0x8e;
//			}
//		}
//	}
//}




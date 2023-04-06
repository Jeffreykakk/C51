#include <REGX51.H>

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

unsigned char ch1[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void display(unsigned int x)
{
	P2=ch1[x];
}

unsigned char ch2[]={0xFE,0xFD,0XFB,0xF7,0xEF,0xDF,0xBF,0x7F};

void place(unsigned int x)
{
	P3=ch2[x];
}

void play()
{
	int i=0;
	for(i=0;i<10;i++)
	{
		display(i);
		Delay(500);
	}
}

void Timer0Init(void)     //1ms
{
	TMOD=TMOD&0XF0;      //低四位清零，高四位不变 &=
	TMOD=TMOD|0X01;      //最低位放置1，高四位不变 |=
	TF0=0;
	TR0=1;
	TH0=0xFC;						//64535/256
	TL0=0x18;						//64535%256+1
	ET0=1;
	EA=1;
	PT0=0;
}


//1s计时
/*
void Timer0_Routine() interrupt 1
{
	static unsigned int count;
	TH0=0xFC;
	TL0=0x18;
	count++;
	if(count==1000)
	{
		count=0;
		
	}
}
*/

unsigned char Key()
{
	unsigned char KeyNumber=99;
	
	if(P1_0==0) {Delay(20);while(P1_0==0);Delay(20);KeyNumber=0;}
	if(P1_1==0) {Delay(20);while(P1_1==0);Delay(20);KeyNumber=1;}
	if(P1_2==0) {Delay(20);while(P1_2==0);Delay(20);KeyNumber=2;}
	if(P1_3==0) {Delay(20);while(P1_3==0);Delay(20);KeyNumber=3;}
	
	return KeyNumber;
}

void initcounter1(unsigned int x)
{
	TMOD=0x06;
	TH0=256-x;
	TL0=256-x;
	ET0=1;
	EA=1;
	TR0=1;
}

// void counter_isr() interrupt 1
//{
//	
//}

void initex0()		//边沿触发
{
	IT0=1;
	EX0=1;
	EA=1;
}



//void ex_isr() interrupt 0
//{
//	
//}

void UartInit(void)
{
	PCON &= 0x7F;		
	SCON = 0x50;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xF9;
	TH1 = 0xF9;
	ET1 = 0;
	TR1 = 1;
}

void UartSend(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}











unsigned char duanma[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
sbit L1=P2^1;
sbit L0=P2^0;

void delay()
{
	unsigned int i,j;
	for(i=0;i<100;i++);
	for(j=0;j<10;j++);
}

void shuzi(unsigned int x)
{
		P1=0x00;
		L1=0;
		L0=1;
		P1=duanma[x%10];
		delay();
			
		L1=1;
		L0=0;
		P1=duanma[x/10];
		delay();
}




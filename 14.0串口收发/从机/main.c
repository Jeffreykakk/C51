#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
unsigned char flag=0,a,i;
unsigned char table_yin[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                           0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void Serial_comInit()
{

  TMOD=0X20;
	TH1=0XF3;
	TL1=0XFD;
	TR1=1;
	SM0=1;
	REN=1;
	SM1=1;
	EA=1;
	ES=1;
	}
void main()
{
  Serial_comInit();
	while(1)
	{
		if(flag==1)
		{
		
		  P0=table_yin[a];
			P2=0;
		
		
		
		}
	
	
	
	}	

}


void ser() interrupt 4
{
	if(RI==1)
  {
		RI=0;
		a=SBUF;
		flag=1;
	}
}

#include <REGX51.H>


void Timer0Init(void)     //1ms
{
	TMOD=TMOD&0XF0;      //����λ���㣬����λ���� &=
	TMOD=TMOD|0X01;      //���λ����1������λ���� |=
	TF0=0;
	TR0=1;
	TH0=0xFC;						//64535/256
	TL0=0x18;						//64535%256+1
	ET0=1;
	EA=1;
	PT0=0;
}


//1s��ʱ
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
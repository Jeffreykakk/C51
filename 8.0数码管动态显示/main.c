#include <REGX51.H>

void Delay1ms(unsigned int xms)		
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
	
}

unsigned char ch1[]={0x76,0x79,0x38,0x38,0x3F,0x00,0x6D,0x7F};
unsigned char ch2[]={0xFE,0xFD,0XFB,0xF7,0xEF,0xDF,0xBF,0x7F};
void main()
{
	while(1)
	{
		int i=0;
		for(i=0;i<8;i++)
		{
			P3=ch2[i];
			P2=ch1[i];
			Delay1ms(5);
		}
	}
}
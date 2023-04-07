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

void main()
{
	while(1)
	{
		P2=0x5B;//0101 1011:2
		Delay1ms(500);
		P2=0x00;
		Delay1ms(500);
		P2=0x6D;//0110 1101:5
		Delay1ms(500);
		P2=0x00;
		Delay1ms(500);
		P2=0x3F;//0011 1111:0
		Delay1ms(500);
		P2=0x00;
		Delay1ms(500);
	}
}
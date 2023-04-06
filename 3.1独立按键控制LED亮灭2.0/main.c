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
		if(P1_0==0)
			{
				Delay1ms(20);
				while(P1_0==0);
				Delay1ms(20);
				P2_0=~P2_0;
			}
	}
}
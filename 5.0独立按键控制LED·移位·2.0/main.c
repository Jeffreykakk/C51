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

int num1,num2,num3,num4;
void main()
{
	while(1)
		{
			if(P1_0==0)
			{
				Delay1ms(20);
				while(P1_0==0);
				Delay1ms(20);
				num1=0x01;
				num2=num1<<num3;
				P2=~num2;
				num3++;
				if(num3==8)
					num3=0;
			}
			if(P1_1==0)
			{
				Delay1ms(20);
				while(P1_1==0);
				Delay1ms(20);
				num1=0x01;
				if(num3==0)
					num3=7;
				else
					num3--;
				num4=num1<<num3;
				P2=~num4;
			}
				
		}
}

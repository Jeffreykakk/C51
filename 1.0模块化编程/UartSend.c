#include <REGX51.H>

void UartSend(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
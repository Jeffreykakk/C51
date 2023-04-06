#include <REGX51.H>

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
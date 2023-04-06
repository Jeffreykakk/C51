#include <REGX51.H>
#include<INTRINS.H>
#include"keyscan.h"
#include"display.h"

//unsigned char ledmode=0,KeyNumber=0;
//void Timer0_Routine() interrupt 1
//{
//	static unsigned int count;
//	TH0=0xFC;
//	TL0=0x18;
//	count++;
//	if(count=1000)
//	{
//		count=0;
//		if(ledmode==0)
//			P2=_crol_(P2,1);
//		if(ledmode==1)
//			P2=_cror_(P2,1);
//	}
//}



//void main()
//{
//	P2=0xfe;
//	Timer0Init();
//			while(1)
//			{
//				KeyNumber=Key();
//				if(KeyNumber)
//				{
//						if(KeyNumber==1)
//						{
//							ledmode++;
//							if(ledmode=2)
//								ledmode=0;
//						}
//				}
//			}
//}

//void main()
//{
//	UartInit();
//	UartSend(0xfe);
//	while(1)
//	{
//		
//	}
//}

void main()
{
	while(1)
	{
		keyscan();
	}
}
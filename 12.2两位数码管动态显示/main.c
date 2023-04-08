#include <REGX51.H>


unsigned char led_mod[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delay(unsigned int time);
void display(unsigned s0,unsigned s1);

 sbit L0=P2^0;
 sbit L1=P2^1;

void main(void)
 {   
   // Write your code here
   while (1)
       display(2,10);

 }

void delay(unsigned int time)
 {
    unsigned int j=0;
    for(;time>0;time--)
       for(j=0;j<125;j++);   
 }


 
 
 void display(unsigned s0,unsigned s1)
{
   unsigned  int m,n,dly,i;
   
   for(m=0;m<s0;m++)
      for(n=0;n<s1;n++)
	 for(dly=0;dly<17;dly++)
	    for(i=0;i<2;i++)
	    {
				 switch(i)
				 {
					 case(0):
						 L0=0;L1=1;
						 P1=led_mod[m];
						 break;
					 case(1):
						 L0=1;L1=0; 
						 P1=led_mod[n];
						break;
				 }
				 
				 delay(29);
				 P1=0x00;
		  }

}


#include <REGX51.H>
typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef char int8_t;
typedef int int16_t;
typedef long int int32_t;
sbit left=P3^5;			//st188 left
sbit right=P3^4;		//st188 right
sbit IN1=P2^1;
sbit ENl=P2^2;
sbit IN2=P2^3;
sbit IN3=P2^4;
sbit EN2=P2^5;
sbit IN4=P2^6;		
uint16_t T_count = 0;
int16_t flag=0;
int16_t n=0;
void main()
{
	TMOD = 0X01;
	TH0 = (65536-10)%256; 
	TL0 = (65536-10)/256;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
  while(1)
    {
		  IN1=1;
			IN2=0;
      IN3=1;
      IN4=0;
			if(left==1 &&right==0){
				enablel=0;
				flag=1;
	}
     if(right==1 && left==0){
	      enabler=0;
			  flag=1;
	}
     if(right==1 && left==1)
 {      
	      enablel=0;
	      enabler=0;
 }
			}
}
void Timer0() interrupt 1
{
	TH0 = (65536-10)%256; 
	TL0 = (65536-10)/256;//T=1ms
	T_count++;
	if(flag==1){
		n=2;
		flag=0;
	}
  if(T_count<= (15+n)){
		enablel=0;
		enabler=0;
	}
	else if (T_count>(15+n)){
		enablel=1;
		enabler=1;
	}
	n=0;
	if(T_count%20==0){
		T_count=0;
	}
}
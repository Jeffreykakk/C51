#ifndef __FUCTIONS_H__
#define __FUCTIONS_H__

void Delay(unsigned int xms);
void display(unsigned int x);
void place(unsigned int x);
void play();
void Timer0Init(void);
unsigned char Key();
void initcounter1(unsigned int x);
void initex0();
void UartInit(void);
void UartSend(unsigned char Byte);
void shuzi(unsigned int x);
void delay();
unsigned char keyscan();

#endif
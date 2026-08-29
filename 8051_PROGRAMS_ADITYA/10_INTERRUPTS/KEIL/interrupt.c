#include<reg51.h>

sbit led = P1^0;

void main()
{
	EA=1;
	EX0=1;
	IE0=1;
	IT0=1;
	
	//IE = 0x84;
	//TCON = 0x0C;
	led=1;
	while(1)
	{
	}
}

void aditya() interrupt 1
{
	led =~led;
}
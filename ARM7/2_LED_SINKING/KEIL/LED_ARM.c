#include<lpc214x.h>

void delay(unsigned int t);

int main()
{
	PINSEL1 = 0X00000000;
	PINSEL2 = 0X00000000;
	
	IODIR0 = 0X00090000;
	IODIR1 = 0X00010000;
	
	while(1)
	{
		IOCLR0 = 0X00090000;
		delay(1);
		IOSET0 = 0X00010000;
		delay(1);
		IOSET0 = 0X00080000;
		delay(1);
		
		IOCLR1 = 0X00010000;
		delay(1);
		IOSET1 = 0X00010000;
	}
}

void delay(unsigned int t)
{
	unsigned int i;
	for(i=0;i<=1000000*t;i++);
}
		
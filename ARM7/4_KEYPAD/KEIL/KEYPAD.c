#include<lpc214x.h>
void delay(unsigned int t);

int main()
{
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00000000;
	
	IODIR0 = 0x000F0000;
	IODIR1 = 0x000F0000;
	
	while(1)
	{
		IOCLR1 = 0x00010000;
		IOSET1 = 0x000E0000;
		
		if((IOPIN1 & 0x00100000)==0)
		{
			IOSET0 = 0x00010000;
		}
	}
}
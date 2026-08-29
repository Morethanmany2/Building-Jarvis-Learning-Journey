#include<lpc214x.h>
int main()
{
	PINSEL1 = 0X000000000;
	IODIR0 = 0X00010000;
	
	IOSET0 = 0X00010000;
	
	while(1)
	{
		if((IOPIN0 & 0X00080000)==0)
		{
			IOCLR0 = 0X00010000;
		}
		else
		{
			IOSET0 = 0X00010000;
		}
	}
}

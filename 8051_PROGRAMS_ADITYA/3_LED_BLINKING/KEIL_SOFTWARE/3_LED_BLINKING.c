#include<reg51.h>

sbit led = P2^0;
void delay(unsigned int t);

void main()
{
	led = 1;
	while(1)
	{
		led = 0;
		delay(1);
		led = 1;
		delay(2);
	}
}

void delay(unsigned int t)
{
	unsigned int i,j;
	
	for(i=0;i<=1275*t;i++)
	{
		for(j=0;j<=100;j++);
	}
}
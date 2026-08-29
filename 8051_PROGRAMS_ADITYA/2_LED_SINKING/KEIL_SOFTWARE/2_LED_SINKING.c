#include<reg51.h>

sbit led=P1^1;

void main()
{
	led = 1;
	while(1)
	{
		led = 0;
	}
}
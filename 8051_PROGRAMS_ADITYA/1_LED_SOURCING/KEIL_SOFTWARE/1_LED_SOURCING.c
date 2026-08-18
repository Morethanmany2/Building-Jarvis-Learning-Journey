#include<reg51.h>
sbit led = P1^0;
void main()
{
	led = 1;
}
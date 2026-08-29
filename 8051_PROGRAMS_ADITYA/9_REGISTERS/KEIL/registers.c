#include<reg51.h>

sbit led = P1^0;
void delay();

void main()
{
	led = 1;
	while(1)
	{
		led = 0;
		delay();
		led = 1;
		delay();
	}
}


void delay()
{
	TMOD = 0x00;
	TH1 = 0x0D; //Starting value
	TL1 = 0xFF;  //Starting value
	
	TR1 = 1;  //start timer
	
	while(TF1== 0);
	TR1 = 0; //stop timer
	TF1 = 0; //use timer again
}
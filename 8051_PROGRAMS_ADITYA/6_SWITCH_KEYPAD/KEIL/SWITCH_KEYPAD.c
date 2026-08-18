#include<reg51.h>

sbit led1 = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
sbit led4 = P1^3;
sbit R1 = P2^0;
sbit R2 = P2^1;
sbit R3 = P2^2;
sbit R4 = P2^3;
sbit C1 = P2^4;
sbit C2 = P2^5;
sbit C3 = P2^6;
sbit C4 = P2^7;

void main()
{
	led1=led2=led3=led4=1;
	while(1)
	{
		R4 = 0;
		R1=R2=R3=1;
		if(C1 == 0)
		{
			led1 = 0;
		}
		if(C2 == 0)
		{
			led2 = 0;
		}
		if(C3 == 0)
		{
			led3 = 0;
		}
		if(C4 == 0)
		{
			led4 = 0;
		}
		
		R3 = 0;
		R1=R2=R4=1;
		if(C1 == 0)
		{
			led1 = 0;
		}
		if(C2 == 0)
		{
			led2 = 0;
		}
		if(C3 == 0)
		{
			led3 = 0;
		}
		if(C4 == 0)
		{
			led4 = 0;
		}
		
		R2 = 0;
		R1=R4=R3=1;
		if(C1 == 0)
		{
			led1 = 0;
		}
		if(C2 == 0)
		{
			led2 = 0;
		}
		if(C3 == 0)
		{
			led3 = 0;
		}
		if(C4 == 0)
		{
			led4 = 0;
		}
		
		R1 = 0;
		R4=R2=R3=1;
		if(C1 == 0)
		{
			led1 = 0;
		}
		if(C2 == 0)
		{
			led2 = 0;
		}
		if(C3 == 0)
		{
			led3 = 0;
		}
		if(C4 == 0)
		{
			led4 = 0;
		}
	}
}

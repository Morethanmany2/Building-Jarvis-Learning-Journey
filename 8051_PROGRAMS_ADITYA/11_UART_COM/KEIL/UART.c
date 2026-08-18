#include<reg51.h>
void uart_start();
void tranx_char(unsigned char ch);
void tranx_string(unsigned char w[]);
unsigned char recx_char();
void recx_string(unsigned int len);
unsigned char word[100];
void main()
{
	uart_start();
	//tranx_char('A');
	//tranx_string("ADITYA");
	tranx_string("Checking...");
	while(1)
	{
		tranx_char(recx_char());
	}
}

void uart_start()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TR1 = 1;
}

void tranx_char(unsigned char ch)
{
	SBUF = ch;
	while(TI == 0);
	TI = 0;
}

void tranx_string(unsigned char w[])
{
	unsigned int i;
	for(i=0;w[i]!='\0';i++)
	{
		tranx_char(w[i]);
	}
}


unsigned char recx_char()
{
	while(RI == 0);
	RI = 0;
	return SBUF;
}

void recx_string(unsigned int len)
{
	unsigned int i;
	for(i=0;i<=len;i++)
	{
		word[i] = recx_char();
	}
}


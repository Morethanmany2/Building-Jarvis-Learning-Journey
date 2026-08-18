#include<reg51.h>

#define LCD P2

sbit RS = P2^4;
sbit EN = P2^5;

void lcd_init();
void lcd_cmd(unsigned int cmd);
void lcd_data(unsigned char dat);
void delay(unsigned int t);
void display(unsigned char w[]);

void main(){
	lcd_init();

	display("Hello Jarvis");
	while(1);
}

void lcd_init()
{
	lcd_cmd(0x28);
	lcd_cmd(0x01);
	lcd_cmd(0x0F);
	lcd_cmd(0xC0);
}

void lcd_cmd(unsigned int cmd)
{
	LCD = (cmd >> 4);
	RS = 0;
	EN = 1;
	delay(1);
	EN = 0;
	
	LCD = cmd;
	RS = 0;
	EN = 1;
	delay(1);
	EN = 0;
}

void lcd_data(unsigned char dat)
{
	LCD = (dat >> 4);
	RS = 1;
	EN = 1;
	delay(1);
	EN = 0;
	
	LCD = dat;
	RS = 1;
	EN = 1;
	delay(1);
	EN = 0;
}

void display(unsigned char w[])
{
	unsigned int i;
	for(i=0;w[i]!='\0';i++)
	{
		lcd_data(w[i]);
	}
}

void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<=127*t;i++)
	{
		for(j=0;j<=10;j++);
	}
}
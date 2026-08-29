#include<reg51.h>

#define LCD P2
sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

void lcd_init();
void lcd_cmd(unsigned int cmd);
void lcd_data(unsigned char dat);
void delay(unsigned int t);

void main()
{
	lcd_init();

	lcd_data('A');
	while(1);
}

void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0F);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned int cmd)
{
	LCD = cmd;
	RS = 0;
	RW = 0;
	EN = 1;
	delay(1);
	EN = 0;
}

void lcd_data(unsigned char dat)
{
	LCD = dat;
	RS = 1;
	RW = 0;
	EN = 1;
	delay(1);
	EN = 0;
}

void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<=127*t;i++)
	{
		for(j=0;j<=10;j++);
	}
}
#include<lpc214x.h>

void lcd_init(void);
void lcd_clr(void);
void lcd_cmd(unsigned int cmd);
void lcd_data(unsigned char dat);
void delay(unsigned int t);

int main()
{
	PINSEL0 = 0X00000000;
	PINSEL1 = 0X00000000;
	IODIR0 = 0X00F0E000;
	lcd_init();
	lcd_data('H');
}

void lcd_init()
{
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x01);
	lcd_cmd(0x0F);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned int cmd)
{
	unsigned int temp;
	IOCLR0 = 0X00F0E000;
	temp = (cmd>>4);
	IOSET0 = (temp <<20);
	IOCLR0 = (1<<13);
	IOCLR0 = (1<<14);
	IOSET0 = (1<<15);
	delay(1);
	IOCLR0 = (1<<15);
	
	IOCLR0 = 0X00F0E000;
	temp = (cmd);
	IOSET0 = (temp <<20);
	IOCLR0 = (1<<13);
	IOCLR0 = (1<<14);
	IOSET0 = (1<<15);
	delay(1);
	IOCLR0 = (1<<15);
}

void lcd_data(unsigned char dat)
{
	unsigned int temp;
	IOCLR0 = 0X00F0E000;
	temp = (dat>>4);
	IOSET0 = (temp <<20);
	IOSET0 = (1<<13);
	IOCLR0 = (1<<14);
	IOSET0 = (1<<15);
	delay(1);
	IOCLR0 = (1<<15);
	
	IOCLR0 = 0X00F0E000;
	temp = (dat>>4);
	IOSET0 = (temp <<20);
	IOSET0 = (1<<13);
	IOCLR0 = (1<<14);
	IOSET0 = (1<<15);
	delay(1);
	IOCLR0 = (1<<15);
}

void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<=1275*t;i++)
	{
		for(j=0;j<=100;j++);
	}
}

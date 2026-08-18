#include<lpc214x.h>

void lcd_init(void);
void lcd_cmd(unsigned int cmd);
void lcd_data(unsigned char dat);
void delay(unsigned int t);
void lcd_clear(void);

int main()
{
	PINSEL0 = 0X00000000;                                                           
	PINSEL1 = 0X00000000;
	IODIR0 = 0X00FFE000;
	lcd_init();
	lcd_data('H');
delay(1);
	lcd_clear();
	//while(1);
}

void lcd_clear()
{
	lcd_cmd(0x01);
}


void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x01);
	lcd_cmd(0x0F);
	lcd_cmd(0x80);
}

void lcd_cmd(unsigned int cmd)
{
	IOCLR0 = 0X00FFE000;
	IOSET0 = (cmd << 16);
	IOCLR0 = (1<<13);
	IOCLR0 = (1<<14);
	IOSET0 = (1<<15);
	delay(1);
	IOCLR0 = (1<<15);
}

void lcd_data(unsigned char dat)
{
	IOCLR0 = 0X00FFE000;
	IOSET0 = (dat << 16);
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
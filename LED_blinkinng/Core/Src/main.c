#include "stm32f1xx.h"

void delay(unsigned int t);

int main(void)
{

	RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC -> CRH &= ~(0XFU << 28);
	GPIOC -> CRH |= (0X2U << 28);

	GPIOC -> CRH &= ~(0XFU << 24);
	GPIOC -> CRH |= (0X8U << 24);

	GPIOC -> ODR |= (1U << 14);

	GPIOC -> BRR = (1U << 15);

	while(1)
	{
//		=======LED BLINKING=========
//		GPIOC -> BSRR |= (1U << 15);
//		delay(10);
//
//		GPIOC -> BRR |= (1U << 15);
//		delay(10);

		if(!(GPIOC -> IDR & (1U << 14)))
		{
			GPIOC -> BSRR |= (1U << 15);
			while(!(GPIOC -> IDR & (1U << 14)));
		}
		else
		{
			GPIOC -> BRR = (1U << 15);
		}
	}

}

void delay(unsigned int t)
{
	volatile unsigned int i,j;
	for(i=0;i<1275U*t;i++)
	{
		for(j=0;j<100U;j++)
		{
			__NOP();
		}
	}
}

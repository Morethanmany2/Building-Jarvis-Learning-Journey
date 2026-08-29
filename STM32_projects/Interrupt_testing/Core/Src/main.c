#include"stm32f1xx.h"

void delay(unsigned int t);
void interrupt(void);

int main(void)
{
	/* Enable GPIOC clock */
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	/* PC13 -> Output Push-Pull, 2 MHz */
	GPIOC->CRH &= ~(0xFU << 20);
	GPIOC->CRH |=  (0x2U << 20);

	/* PC14 -> Output Push-Pull, 2 MHz */
	GPIOC->CRH &= ~(0xFU << 24);
	GPIOC->CRH |=  (0x2U << 24);

	/* PC15 -> Output Push-Pull, 2 MHz */
	GPIOC->CRH &= ~(0xFU << 28);
	GPIOC->CRH |=  (0x2U << 28);

	GPIOB->CRH &= ~(0xFU << 16);
	GPIOB->CRH |=  (0x8U << 16);
	GPIOB->ODR |= (1U << 12);

	while(1)
	{

	}
}

void interrupt(void)
{

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

#include "stm32f1xx.h"

void delay(unsigned int t);

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

    GPIOC->BRR = (1U << 13);
    GPIOC->BRR = (1U << 14);
    GPIOC->BRR = (1U << 15);
    while (1)
    {
    	if(!(GPIOB -> IDR & (1U << 12)))
    	{
    		GPIOC->BSRR = (1U << 13);
    		GPIOC->BRR = (1U << 14);
    		GPIOC->BRR = (1U << 15);
    		delay(1);

    		GPIOC->BSRR = (1U << 13);
    		GPIOC->BSRR = (1U << 14);
    		GPIOC->BRR = (1U << 15);
    		delay(1);

    		GPIOC->BSRR = (1U << 13);
    		GPIOC->BSRR = (1U << 14);
    		GPIOC->BSRR = (1U << 15);
    		while(!(GPIOB -> IDR & (1U << 12)));
    	}
    	else if(GPIOB -> IDR & (1U << 12)){
    		GPIOC->BSRR = (1U << 13);
    		GPIOC->BSRR = (1U << 14);
    		GPIOC->BRR = (1U << 15);
    		delay(1);

    		GPIOC->BSRR = (1U << 13);
    		GPIOC->BRR = (1U << 14);
    		GPIOC->BRR = (1U << 15);
    		delay(1);

    		GPIOC->BRR = (1U << 13);
    		GPIOC->BRR = (1U << 14);
    		GPIOC->BRR = (1U << 15);
    		while(GPIOB -> IDR & (1U << 12));
    	}
    	else{
    		GPIOC->BRR = (1U << 13);
    		GPIOC->BRR = (1U << 14);
    		GPIOC->BRR = (1U << 15);
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

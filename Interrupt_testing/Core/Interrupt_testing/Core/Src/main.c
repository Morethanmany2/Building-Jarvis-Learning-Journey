#include "stm32f1xx.h"

void delay(unsigned int t);


int main (void)
{
//	ENABLING THE GPIO CLOCKS
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

//	ENABLES THE INTERRUPT CLOCK AFIO
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

//LED ON PC14
	GPIOC -> CRH &= ~(0XFU << 24);
	GPIOC -> CRH |= (0X2U << 24);

//LED ON PC15
	GPIOC -> CRH &= ~(0XFU << 28);
	GPIOC -> CRH |= (0X2U << 28);

//BUTTON ON PB12
	GPIOB->CRH &= ~(0xFU << 16);
	GPIOB->CRH |=  (0x8U << 16);

	GPIOB->ODR|= (1U << 12);

//	CONNECTING INTERRUPT PIN TO PB12
	AFIO->EXTICR[3] &= ~(0xFU << 0);
	AFIO->EXTICR[3] |=  (0x1U << 0);

//	ENABLES THE EXTI12 INTERUPT
	EXTI->IMR |= (1U << 12);

//	FALLING EDGE DETECTION
	EXTI->FTSR |= (1U << 12);

//	ENABLES NVIC INTERRUPT ROUTINE
	NVIC_EnableIRQ(EXTI15_10_IRQn);


//	SETTING LEDS HIGH
	GPIOC -> BSRR = (1 << 14);
	GPIOC -> BSRR = (1 << 15);

	while(1)
	{
		GPIOC -> BRR = (1U << 14);
		delay(100);
		GPIOC -> BSRR = (1 << 14);
	}
}


void delay(unsigned int t){
	volatile unsigned int i,j;
	for(i=0;i<1275U*t;i++)
	{
		for(j=0;j<100U;j++)
		{
			__NOP();
		}
	}
}

#include "stm32f1xx.h"

//COUNTER FOR CONTROLLING BRIGHTNESS
volatile uint8_t brightness_state = 0;



int main(void)
{
//	ENABLINGTHE GPIO CLOCKS
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

//	ENABLING THE INTERRUPT CLOCK
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

//	ENABLING THE TIMER2 CLOCK
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

// PA0 → Alternate Function Push-Pull
	GPIOA->CRL &= ~(0xFU << 0);
	GPIOA->CRL |=  (0xBU << 0);

//	PB12 CONFIGURATION
	GPIOB->CRH &= ~(0xFU << 16);
	GPIOB->CRH |=  (0x8U << 16);

	GPIOB->ODR|= (1U << 12);

//	Slows down the timer counter
	TIM2 -> PSC = 7;

//	Defines the PWM period
	TIM2 ->ARR = 999;

//	Defines how long the PWM output stays active
	TIM2 ->CCR1 = 999;

//	bits 6:4 = 110  → PWM Mode 1
//	bit  3   = 1    → preload enabled
//	bits 1:0 = 00   → CH1 is output
	TIM2->CCMR1 &= ~(0xFU << 0);
	TIM2->CCMR1 |= (6U << 4) | (1U << 3);

//	Enable Channel 1 output and determine its polarity.
	TIM2->CCER |= (1U << 0) | (1U << 1);

//	UPDATE GENERATION BIT
	TIM2->EGR = (1U << 0);

//	START TIM2
	TIM2->CR1 |= (1U << 0) | (1U << 7);

//	SETTING UP INTERRUPT PIN
	AFIO->EXTICR[3] &= ~(0xFU << 0);
	AFIO->EXTICR[3] |=  (0x1U << 0);

//	ENABLES THE EXTI12 INTERUPT
	EXTI->IMR |= (1U << 12);

//	FALLING EDGE DETECTION
	EXTI->FTSR |= (1U << 12);

//	ENABLES NVIC INTERRUPT ROUTINE
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	while(1)
	{
		GPIOA -> BSRR = (1U << 0);
	}
}

// https://github.com/junaidpv/stm8/blob/master/src/time.c

#include "stm8.h"

volatile uint32_t __global_millis = 0;

void timer4_millis_isr() __interrupt(TIM4_ISR) 
{
	__global_millis++;
	//clear_bit(TIM4_SR, TIM4_SR_UIF);  // Clear interrupt flag
	TIM4_SR &= ~TIM4_SR_UIF;
}

void init_millis()
{
	enable_interrupts();
	TIM4_PSCR = 3; // So prescaler will be 2^3 = 8
	// Timer 4 will increment in each 4 micro seconds
	TIM4_ARR = 249; // So timer 4 will overflow in each milli second.
	//set_bit(TIM4_IER, TIM4_IER_UIE);  // Enable update interrupt.
	TIM4_IER |= TIM4_IER_UIE;
	//set_bit(TIM4_EGR, TIM4_EGR_UG);
	//set_bit(TIM4_CR1, TIM4_CR1_CEN);  // Enable timer 4.
	TIM4_CR1 |= TIM4_CR1_CEN;
}

/**
 * Return current milli seconds.
 */
uint32_t millis()
{
	return __global_millis;
}

void delay_millis(u32 ms)
{
	u32 start = __global_millis;
	while(__global_millis - start < ms);
}


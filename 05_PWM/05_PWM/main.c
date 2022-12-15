/*
 * 05_PWM.c
 *
 * Created: 10.02.2018 14:50:01
 * Author : Joachim
 */ 

// this code sets up counter0 for an 8kHz PWM wave @ 16Mhz Clock

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
	
	// Datadirection Pin D6 als Ausgang
	DDRD |= (1 << DDD6);

	OCR0A = 255;  // 256 * Duty / 100
	// set PWM for 75% duty cycle


	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR0A |= /*(1 << WGM02) | */(1 << WGM01)  | (1 << WGM00);
	// set fast PWM Mode

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
	
	
	
	while (1)
	{
	
	}
}

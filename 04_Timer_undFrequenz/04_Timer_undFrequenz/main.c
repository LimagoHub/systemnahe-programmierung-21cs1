/*
 * 04_Timer_undFrequenz.c
 *
 * Created: 10.02.2018 09:39:52
 * Author : Joachim
 */ 

// this code sets up a timer0 for 1ms @ 16Mhz clock cycle
// in order to function as a time delay at the begining of the main loop
// using no interrupts

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLEAR_BIT(PORT,BIT) PORT&=~(1<<BIT)


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt
{
	PORTB = ~PORTB;
	
}


int main(void)
{

	DDRB = 0xFF;
	PORTB = 0;

	// Set the Timer Mode to CTC
	TCCR0A |= (1 << WGM01);

	// Set the value that you want to count to
	OCR0A = 70; // Kammerton A
	

	TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect

	sei();         //enable interrupts


	TCCR0B |= (1 << CS02);
	// set prescaler to 256 and start the timer


	while (1)
	{
		//main loop
	}
}


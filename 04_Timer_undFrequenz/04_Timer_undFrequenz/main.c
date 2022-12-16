/*
 * 04_Timer_undFrequenz.c
 *
 * Created: 10.02.2018 09:39:52
 * Author : Joachim
 */ 

// this code sets up a timer0 for 1ms @ 16Mhz clock cycle
// in order to function as a time delay at the begining of the main loop
// using no interrupts



#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt
{
	PORTB = ~PORTB;
	
}
ISR(INT0_vect) {
	OCR0A = 119; // Kammerton C
}
ISR(INT1_vect) {
	OCR0A = 70; // Kammerton A
}


int main(void)
{

	// Data Direction Register
	DDRB = 0xFF;
	PORTB = 0;

	// Set the Timer Mode to CTC
	TCCR0A |= (1 << WGM01);

	// Set the value that you want to count to
	OCR0A = 70; // Kammerton A
	

	TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect

	EICRA = (1 << ISC01) | (1 << ISC11); // Verhalten z.B. rising Edge
	EIMSK = (1 << INT0) | (1 << INT1); // aktivieren der Interrupts

	sei();         //enable interrupts


	TCCR0B |= (1 << CS02);
	// set prescaler to 256 and start the timer


	while (1)
	{
		
	}
}


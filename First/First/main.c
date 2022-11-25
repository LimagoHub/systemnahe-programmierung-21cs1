/*
 * First.c
 *
 * Created: 25.11.2022 11:10:17
 * Author : JoachimWagner
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	// Data Direction Register
	DDRB = (1 << DDB5); // gesetztes Bit ist Ausgang  
	PORTB = (1 << PORTB5); // 
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB &= ~(1 << PORTB5);
		_delay_ms(500);
		
		PORTB |= (1 << PORTB5);
		_delay_ms(500);
		
	
    }
}


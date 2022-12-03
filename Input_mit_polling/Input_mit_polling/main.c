/*
 * Input_mit_polling.c
 *
 * Created: 03.12.2022 12:00:42
 * Author : JoachimWagner
 */ 

#include <avr/io.h>


int main(void)
{
    
	// PB5 als ausgang
	DDRB = (1 << DDB5);
	DDRB = 0x20;
	DDRB = 0b00100000;
	
	// PD2 und PD3 als Eingang (Alles auf Port D)
	DDRD = 0;
	
	// Pull auf D2 und D3
	PORTD = (1 << PORTD2) | ( 1 << PORTD3);
	
	
    while (1) 
    {
		// Messen ob D2 gesetzt ist
		if((PIND & ( 1 << PIND2))  == 0) {
			PORTB = ( 1 << PORTB5);
		}
		
			// Messen ob D2 gesetzt ist
		if((PIND & ( 1 << PIND3))  == 0) {
			PORTB = 0;
		}

    }
}


/*
 * eingabe_mit_interrupt.c
 *
 * Created: 03.12.2022 13:34:03
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
	PORTB = (1 << PORTB5);
}
ISR(INT1_vect) {
	PORTB = 0;
}

int main(void)
{
	
		DDRB = (1 << DDB5);
		
		// PD2 und PD3 als Eingang (Alles auf Port D)
		DDRD = 0;
		
		// Pull auf D2 und D3
		PORTD = (1 << PORTD2) | ( 1 << PORTD3);
		
		EICRA = (1 << ISC01) | (1 << ISC11); // Verhalten z.B. rising Edge
		EIMSK = (1 << INT0) | (1 << INT1); // aktivieren der Interrupts
		
		sei(); // Globale Aktivierung aller Interrupts
		
    /* Replace with your application code */
    while (1) 
    {
    }
}


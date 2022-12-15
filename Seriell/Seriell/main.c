/*
 * Seriell.c
 *
 * Created: 15.12.2022 11:12:38
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL                       // Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD -1

static volatile int8_t value;

ISR (USART_RX_vect)
{
	value = UDR0; // Empfangen
	UDR0 = value; // Als echo zurück senden
}


int main(void)
{
	// Baudrate setzen
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
	
	
	// RX Datenempfang aktivieren TX Datensenden aktivieren (DDR nicht notwendig)
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);   
	
	
	// Protokoll 
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Set frame: 8data, 1 stp
	
	
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
	
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
	
		
    }
}


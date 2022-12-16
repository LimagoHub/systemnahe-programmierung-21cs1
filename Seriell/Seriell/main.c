/*
 * Seriell.c
 *
 * Created: 15.12.2022 11:12:38
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdlib.h>

#include "uart.h"  

#include <util/delay.h>                  


//static volatile int8_t value;
//
//ISR (USART_RX_vect)
//{
	//value = UDR0; // Empfangen
	//UDR0 = value; // Als echo zurück senden
//}




int main(void)
{
	
	
	uart_init(9600);
	uart_send_string_ln("Hallo Seriell");
	
    /* Replace with your application code */
    while (1) 
    {
		
		
		
		int16_t value = 1000;
		
		uart_send_int(value);
		uart_send_string_ln("");
		_delay_ms(1000);
    }
}


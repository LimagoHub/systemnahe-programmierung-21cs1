/*
 * AnalogReader.c
 *
 * Created: 16.12.2022 07:44:38
 * Author : JoachimWagner
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"
#include "adc.h"



int main(void)
{
   adc_init();
   uart_init(9600);
   uart_send_string_ln("Starte Konvertierung");
   
  
   
   
    while (1) 
    {
		for(uint8_t channel = 0; channel < 2; channel ++) {
			 uart_send_string("Channel: ");
			 uart_send_int(channel);
			 uart_send_string_ln("");
			 uart_send_int(adc_read(channel));
			 uart_send_string_ln("");
		}
		_delay_ms(500);
		
    }
}


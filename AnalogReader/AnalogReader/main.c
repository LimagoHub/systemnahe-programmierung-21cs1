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




int main(void)
{
   
   uart_init(9600);
   uart_send_string_ln("Starte Konvertierung");
   
  
   
   
    while (1) 
    {
		
		
    }
}


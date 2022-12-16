/*
 * uart.c
 *
 * Created: 15.12.2022 17:03:38
 *  Author: JoachimWagner
 */ 

#include "uart.h"

void uart_init(uint32_t baudrate){
	
		uint16_t MYUBRR = F_CPU/16/baudrate-1;
	
		UBRR0H = MYUBRR >> 8;
		UBRR0L = MYUBRR;
		
		// RX Datenempfang aktivieren TX Datensenden aktivieren (DDR nicht notwendig)
		UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
		
		//Protokoll
		UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // Set frame: 8data, 1 stp
		
		UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
}

void uart_send_char(char c){
	while ( !(UCSR0A & (1 << UDRE0)) )
	{
		
	}
	UDR0 = c;
}
void uart_send_string(char *message){
	while(*message)
		uart_send_char(*message ++);
}
void uart_send_string_ln(char *message){
	uart_send_string(message);
	uart_send_string("\r\n");
}
char uart_receive_char(){
	while ( !(UCSR0A & (1 << RXC0)) ){
		
	}
	return UDR0;
}

void uart_send_int(int16_t value) {
	char send_buffer[10];
	uart_send_string(itoa(value,send_buffer,10));
}

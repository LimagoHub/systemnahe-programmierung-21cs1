/*
 * uart.h
 *
 * Created: 15.12.2022 17:00:06
 *  Author: JoachimWagner
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <stdlib.h>

#define F_CPU 16000000UL

void uart_init(uint32_t baudrate);
void uart_send_char(char c);
void uart_send_string(char *message);
void uart_send_string_ln(char *message);
char uart_receive_char();
void uart_send_int(int16_t value);


#endif /* UART_H_ */
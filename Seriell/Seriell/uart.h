/*
 * uart.h
 *
 * Created: 16.12.2022 09:06:33
 *  Author: JoachimWagner
 */ 

#pragma once
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

void uart_init(uint32_t baudrate);
void uart_send_char(char c);
char uart_receive_char();
void uart_send_string(char *message);
void uart_send_string_ln(char *message);
void uart_send_int(int value);




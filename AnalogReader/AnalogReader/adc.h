/*
 * adc.h
 *
 * Created: 16.12.2022 10:49:43
 *  Author: JoachimWagner
 */ 

#pragma once
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void adc_init();// 10 bit
uint16_t adc_read(uint8_t channel);
/*
 * adc.c
 *
 * Created: 16.12.2022 10:53:37
 *  Author: JoachimWagner
 */ 
#include "adc.h"

void adc_init(){
	ADMUX = (1 << REFS0); // ADLAR auf 1 wenn 8 bit
	ADCSRA = (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);// ADC aktivieren und prescaler setzen
}
uint16_t adc_read(uint8_t channel){

	ADMUX &= 0xf0;	
	ADMUX |= (channel & 0xf);

	ADCSRA |= (1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	return ADCL | (ADCH << 8); // Im free running modus loesst das lesen des HIGH-register die naechste Konvertierung aus
}
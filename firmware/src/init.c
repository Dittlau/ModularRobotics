/*
 * init.c
 *
 * Created: 05-06-2012 21:14:28
 *  Author: Daniel
 */ 

#include "init.h"


void portInit() {
	DDRC = 0b00110001;
	DDRE = 0x00;
	PORTE |= 0b11110000;
}

void adcInit() {
	DDRA  = 0xFC;
	PORTA = 0xFC;
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);	// ADC Enable, Clock 1/64div.
	ADMUX = 1;
	
}

void timerInit() {
	TCCR1B = (1<<CS11)|(1<<CS10); //64 Prescaler
	OCR1A = 124; //Equals delay 1 ms
	TIMSK1 = (1<<OCIE1A); //Enable Output Compare Match Interrupt
	TCNT1 = 0; //reset timer/counter 1
}
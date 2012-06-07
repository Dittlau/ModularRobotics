/*
 * adc.c
 *
 *  Created on: 06/06/2012
 *      Author: Kinna
 */

/**
 * Initializes ADC
 * @param sensor_value The value returned from the sensor
 */
void ADCInit(int port_no){
	// Enable ADC and setting division factor to 64
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
	ADMUX = port_no; // numbers from 1-7 (one for each IR sensor?)
}

int ADCConvert(void){
	PORTA &= ~0x80; // ADC Port 1 IR ON

	_delay_us(12); // Short Delay for rising sensor signal
	ADCSRA |= (1 << ADIF); // AD-Conversion Interrupt Flag Clear
	ADCSRA |= (1 << ADSC); // AD-Conversion Start

	while( !(ADCSRA & (1 << ADIF)) ); // Wait until AD-Conversion complete

	PORTA = 0xFC; // IR-LED Off

	return ADC;
}

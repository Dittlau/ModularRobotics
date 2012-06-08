/*
 * Robot_3.c
 *
 * Created: 05-06-2012 18:57:21
 *  Author: Daniel
 */ 

#include "init.h"
#include <avr/interrupt.h>
#include "serial.h"
#include "dynamixel.h"

ISR(TIMER1_COMPA_vect){
	TCNT1 = 0; // resets timer
}

//ISR(USART0_RX_vect) {
	//data = UDR0;
	//
//}


int main(){
	portInit();
	serial_initialize(57600);
	dxl_initialize( 0, 1 ); // init with baud = 1 Mbps
	timerInit();
	adcInit();
	sei(); //Enables global interrupts

	while(1) {
		
	PORTA &= ~0x80;			// ADC Port 1 IR ON
	LEDON_MANAGE;
	printf("Running...");
	ADCSRA |= (1 << ADIF);		// AD-Conversion Interrupt Flag Clear
	ADCSRA |= (1 << ADSC);		// AD-Conversion Start
	while( !(ADCSRA & (1 << ADIF)) );
	PORTA = 0xFC;
	
	LEDOFF_MANAGE;
	printf("ADC: %d \n",ADC);
	_delay_ms(500);		
	}

	return 0;
}

/*
 * Robot_3.c
 *
 * Created: 05-06-2012 18:57:21
 *  Author: Daniel
 */ 
#define F_CPU 16000000UL
#include <stdio.h>
#include <avr/interrupt.h>
#include "init.h"
#include "serial.h"
#include "dynamixel.h"
#include "adc.h"
#include "legs.h"


int main(){
	//portInit();
	serial_initialize(57600);
	dxl_initialize( 0, 1 ); // init with baud = 1 Mbps
	ADCInit();
	sei(); //Enables global interrupts
	
	move(FORWARD,1);
	while(1) {


	}

	return 0;
}

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
#include "wheel.h"


int main(){
	//portInit();
	serial_initialize(57600);
	dxl_initialize( 0, 1 ); // init with baud = 1 Mbps
	ADCInit();
	sei(); //Enables global interrupts

	unsigned int distanceLeft, distanceRight, speedLeft, speedRight, front;
	unsigned char speedcalibration;
	while(1) {
		printf("%d\n\n",getSensorValue(1));
		_delay_ms(1000);

		// Get sensor reading (in cm)
		/*front = DMSDistance(getSensorValue(1));
		distanceLeft = IRValue(getSensorValue(3));
		distanceRight = IRValue(getSensorValue(4));

		// Calculating the required speed
		speedcalibration = 5;
		speedRight = (int)(front-20*distanceLeft);
		speedLeft = (int)(front-20*distanceRight);

		printf("%d   %d\n\n",speedLeft,speedRight);
	
		// Making the wheels spin
		wheel(1,-speedRight);
		wheel(2,speedLeft);*/

	}

	return 0;
}

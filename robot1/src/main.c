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
		//printf("%d   %d   %d   %d   %d\n\n",getSensorValue(3),getSensorValue(4),getSensorValue(5),getSensorValue(2),getSensorValue(6));
		//_delay_ms(1000);

		// Get sensor reading (in cm)
		front = DMSDistance(getSensorValue(1));
		distanceLeft = IRDistance(getSensorValue(3));
		distanceRight = IRDistance(getSensorValue(5));

		// Calculating the required speed
		speedcalibration = 5;
		speedRight = (int)(front+2*(distanceLeft-distanceRight));
		speedLeft = (int)(front+2*(distanceRight-distanceLeft));

		printf("%d   %d\n\n",speedLeft,speedRight);
	
		// Making the wheels spin (in cm/s)
		wheel(1,-speedRight);
		wheel(2,speedLeft);

	}

	return 0;
}

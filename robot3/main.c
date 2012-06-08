/*
 * Robot_3.c
 *
 * Created: 05-06-2012 18:57:21
 *  Author: Daniel
 */ 

#include <stdio.h>
#include <avr/interrupt.h>
#include "init.h"
#include "serial.h"
#include "dynamixel.h"
#include "adc.h"
//#include "wheel.h"


int main(){
	//portInit();
	//serial_initialize(57600);
	dxl_initialize( 0, 1 ); // init with baud = 1 Mbps
	adcInit();
	sei(); //Enables global interrupts

	unsigned int distanceLeft, distanceRight, speedLeft, speedRight;
	unsigned char speedcalibration;
	while(1) {
	
	// Get sensor reading (in cm)
	distanceLeft = IRDistance(getSensorValue(1));
	distanceRight = IRDistance(getSensorValue(4));
	
	// Calculating the required speed
	speedcalibration = 5;
	speedLeft = distanceRight*speedcalibration;
	speedRight = distanceLeft*speedcalibration;
	
	// Making the wheels spin (in cm/s)
	wheel(1,speedLeft);
	wheel(2,speedRight);
		
	}

	return 0;
}

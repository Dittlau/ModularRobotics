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


int main(){
	//portInit();
	//serial_initialize(57600);
	dxl_initialize( 0, 1 ); // init with baud = 1 Mbps
	adcInit();
	sei(); //Enables global interrupts

	while(1) {
	
	// Get sensor reading (in cm)
	distanceLeft IRdistance(getSensorValue(1));
	distanceRight IRdistance(getSensorValue(4));
	
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

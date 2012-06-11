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

	unsigned int distanceLeft, distanceRight, front, movingLeft, movingRight;
	signed int speedLeft, speedRight;
	while(1) {
		//printf("%d   %d\n\n",getSensorValue(3),getSensorValue(4));
		//_delay_ms(1000);

		// Get sensor reading (in cm)
		front = DMSDistance(getSensorValue(1));
		distanceLeft = IRValue(getSensorValue(3));
		distanceRight = IRValue(getSensorValue(4));

		// Calculating the required speed
		speedRight = (int)((front-40*distanceLeft));
		speedLeft = (int)((front-40*distanceRight));

		movingLeft = dxl_read_byte( 1, 38 );
		movingRight = dxl_read_byte(2,38);

		if(movingLeft < 15 && movingRight < 15){
			wheel(1,0);
			wheel(2,-20);
			_delay_ms(1000);
		}else{
			wheel(1,-speedRight);
			wheel(2,speedLeft);
		}


		printf("%d   %d  -  %d\n\n",speedLeft,speedRight,getSensorValue(1));
		//_delay_ms(1000);
		// Making the wheels spin


	}

	return 0;
}

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "wheel.h"
#include "rotator.h"



int main(){
	int rotating = 0;
	int start = 0;
	int speed = 80;
	int rotator_speed = 20;
	int level = 1;
	int count = 0;

	serial_initialize(57600);
	wheelInit();
	deactivateBarrier(8,speed);

	// Setting all LEDs to output
	DDRC |= 0x7F;

	while(1){
		// Waiting for start-signal
		while(!start){
			start = START;
			if(start){
				wheel(2,rotator_speed);
				_delay_ms(1000);
				rotating = dxl_read_byte(2,38);
			}
		}

		// Playing
		while(rotating){
			rotating = dxl_read_byte(2,38); // present speed
			if(!rotating){
				wheel(2,0);
				_delay_ms(250);
				start = 0;
				blinkLEDs();
				deactivateBarrier(8,speed);
			}
			if(ready(8)){
				activateBarrier(8,speed);
			}
			/*if(touch(getSensorValue(1))){
				deactivateBarrier(8,speed);
				count++;
			}*/
		}

	}
	return 0;
}





#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "legs.h"



int main(){
	int state = 2;
	int state_turn = 1;
	int distance, angle;
	int left_angle = 40;
	int right_angle = 40;
	serial_initialize(57600);
	ADCInit();
	legsInit();

	// Ready position
	forward(1,left_angle,right_angle);
	while(1)
	{
		distance = forward(state,left_angle,right_angle);
		if(state == 1){
			left_angle = getAngle(distance);
			if(left_angle < right_angle) right_angle = 40;
			else left_angle = 40;
		}
		else if(state == 3){
			right_angle = getAngle(distance);
			if(right_angle < left_angle) left_angle = 40;
			else right_angle = 40;
		}
		// If it's close to a wall it will turn until the wall is no longer within 20 cm
		else if((state == 2 || state == 4) && distance < 20){
			if(left_angle > right_angle) angle = -40;
			else angle = 40;
			while(distance < 30){
				distance = turn(state_turn,angle);
				state_turn++;
				if(state_turn > 4) state_turn = 1;
			}
			state_turn = 1;
		}
		state++;
		if(state > 4) state = 1;
		//printf("%d   %d\n",left_angle,right_angle);

	}

	return 0;
}





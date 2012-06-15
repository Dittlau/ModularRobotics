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
	int state = 1;
	int distance;
	int left_angle = 40;
	int right_angle = 40;
	serial_initialize(57600);
	ADCInit();
	legsInit();

	while(1)
	{


		distance = forward(state,left_angle,right_angle);
		if(state == 1) left_angle = getAngle(distance);
		else if(state == 3) right_angle = getAngle(distance);
		else if((state == 2 || state == 4) && distance < 20){
			left_angle = 0;//getSpeed(distance);
			right_angle = 0;//getSpeed(distance);
		}
		state++;
		if(state > 4) state = 1;
		printf("%d   %d\n",left_angle,right_angle);

	}



	return 0;
}





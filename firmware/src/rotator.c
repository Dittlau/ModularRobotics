#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "rotator.h"
#include "dynamixel.h"

void blinkLEDs(void){
	int i = 0;
	for(i = 0; i < 4; i++){
		LED1_ON;
		LED2_ON;
		LED3_ON;
		LED4_ON;
		LED5_ON;
		LED6_ON;
		_delay_ms(500);
		LED1_OFF;
		LED2_OFF;
		LED3_OFF;
		LED4_OFF;
		LED5_OFF;
		LED6_OFF;
		_delay_ms(500);
	}
}
/**
 * Makes a barrier start moving to stop the rotator
 * @param id The id of the dynamixel controlling the barrier
 * @param speed The speed og the barrier
 */
void activateBarrier(int id, int speed){
	dxl_write_word(id, MOVING_SPEED_L, speed);
	dxl_write_word(id, GOAL_POSITION_L, convert(90));
}

void deactivateBarrier(int id, int speed){
	dxl_write_word(id, MOVING_SPEED_L, speed);
	dxl_write_word(id, GOAL_POSITION_L, 512);
}

int ready(int id){
	int ready;
	ready = dxl_read_byte(id, MOVING_SPEED_L);
	printf("Ready: %d\n",ready);
	if(ready > 0) return 1;
	else return 0;
}

unsigned int convert(int degree){
	unsigned int converted;
	if(degree < -60) degree = -60;
	else if(degree > 60) degree = 60;

	converted = (unsigned int)((degree + 150)*3.4);
	return converted;
}

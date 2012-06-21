#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "rotator.h"
#include "dynamixel.h"

/**
 * Makes all 6 LEDs on the controller blink 4 times.
 */
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
 * Makes a barrier start moving to stop the rotator.
 * @param id The id of the dynamixel controlling the barrier
 * @param speed The speed of the barrier
 */
void activateBarrier(int id, int speed){
	dxl_write_word(id, MOVING_SPEED_L, speed);
	dxl_write_word(id, GOAL_POSITION_L, 850);
}

/**
 * Makes a barrier go back to the start position.
 * @param id The id of the dynamixel controlling the barrier
 * @param speed The speed of the barrier
 */
void deactivateBarrier(int id, int speed){
	dxl_write_word(id, MOVING_SPEED_L, speed);
	dxl_write_word(id, GOAL_POSITION_L, 512);
}

/**
 * Checks is a barrier is ready to start moving towards the rotor.
 * @param id The id of the dynamixele controlling the barrier
 * @return 1 if the barrier is ready and 0 otherwise
 */
int ready(int id){
	return !dxl_read_byte(id, MOVING);
}



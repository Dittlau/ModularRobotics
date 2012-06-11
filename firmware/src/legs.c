#include <avr/interrupt.h>
#include "serial.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "legs.h"

/**
 * Initialize the servos
 */
void legsInit(void){
	dxl_initialize( 0, DEFAULT_BAUDNUM ); // Not using device index
	
	// Define maximum angles for joints
	
	
	dxl_write_word(3, P_CCW_ANGLE_L, 0 );
	dxl_write_word(3, P_CCW_ANGLE_H, 0 );
	
	sei();	// Interrupt Enable
}

/**
 * Moves the robot forward
 * @param direction Direction of movement, either forward or back.
 * @param distance The distance moved.
 */
void move(char direction, int distance){
	if (direction==FORWARD){
		
	}
	else if (direction==BACK){
		
	}
	
	
}

/**
 * Turns the robot
 * @param direction Direction of turn, either left or right.
 * @param times The number of 45 degree turns made.
 */
void turn(char direction, int times){
	
	
}
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
	
	// Define maximum angles for joints (is it needed???)
		
	//dxl_write_word(3, P_CCW_ANGLE_L, 0 );
	//dxl_write_word(3, P_CCW_ANGLE_H, 0 );
	
	sei();	// Interrupt Enable
}

/**
 * Moves the robot forward
 * @param leg The leg to be moved, either front-left, front-right, back-left or back-right.
 * @param direction Direction of movement, either forward or back.
 * @param length The length of movement.
 * @param speed The speed of movement.
 */
void move(char leg, char angle, char length, char speed){
	if (leg==FRONT_LEFT){
		
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 800 );	// turn ankle for balance
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, 1023 );	// move hip
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 500 );	// turn ankle back
		
		
	}
	else if (leg==FRONT_RIGHT){
		
	}
	else if (leg==BACK_LEFT){
	
	}	
	else if (leg==BACK_RIGHT){
		
	}	
}

/**
 * Turns the robot
 * @param direction Direction of turn, either left or right.
 * @param times The number of 45 degree turns made.
 */
//void turn(char direction, char times){
	
	
//}

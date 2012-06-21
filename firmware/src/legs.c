#include <avr/interrupt.h>
#include <util/delay.h>
#include "serial.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "legs.h"
#include "adc.h"

/**
 * Initialize the servos
 */
void legsInit(void){
	dxl_initialize( 0, DEFAULT_BAUDNUM ); // Not using device index
	
	sei();	// Interrupt Enable

	// Set speed of dynamixels
	dxl_write_word( BROADCAST_ID, 32, 1000);

}

/*
 * Makes the robot move into a given state.
 * @param state The state to move into, should be in the interval [1;4]
 * @param left_angle Determines how much the left side of the robot need to move
 * @param right_angle Determines how much the right side of the robot need to move
 * @return The distance in cm read from the DMS sensor
 */
int forward(int state,int left_angle, int right_angle){
	int head_angle = 60;
	switch(state){
	case 1:
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(left_angle));
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(right_angle));
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, convert(-left_angle));
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, convert(-right_angle));
		
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, convert(0));
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, convert(40));
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, convert(40));
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, convert(0));
		
		dxl_write_word(HEAD, GOAL_POSITION_L, convert(-head_angle));

		break;
		
	case 2:
	
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(-left_angle));
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(-right_angle));
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, convert(left_angle));
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, convert(right_angle));
		
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, convert(0));
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, convert(40));
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, convert(40));
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, convert(0));
		
		dxl_write_word(HEAD, GOAL_POSITION_L, convert(0));
		
		break;
		case 3:
		
		
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(-left_angle));
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(-right_angle));
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, convert(left_angle));
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, convert(right_angle));
		
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, convert(-40));
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, convert(0));
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, convert(0));
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, convert(-40));
		
		dxl_write_word(HEAD, GOAL_POSITION_L, convert(head_angle));
		
		
		break;
		case 4:
		
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(left_angle));
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(right_angle));
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, convert(-left_angle));
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, convert(-right_angle));
		
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, convert(-40));
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, convert(0));
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, convert(0));
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, convert(-40));
		
		dxl_write_word(HEAD, GOAL_POSITION_L, convert(0));
		
		
		break;

	}

	_delay_ms(160);
	//sprintf("%d\n",getSensorValue(6))
	return DMSDistance(getSensorValue(6));
}

/*
 * Makes the robot turn on the spot.
 * @param state The state to move into, should be in the interval [1;4]
 * @param angle Determines how long steps to take
 * @return The distance in cm read from the DMS sensor
 */
int turn(int state,int angle){
	switch(state){
		case 1:
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(angle));
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(angle));
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, convert(angle));
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, convert(angle));
		_delay_ms(200);
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, convert(-40));
		_delay_ms(200);
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(-angle));
		_delay_ms(200);
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, convert(0));
		//_delay_ms(200);
		
		break;
		
		case 2:
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, convert(40));
		_delay_ms(200);
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(-angle));
		_delay_ms(200);
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, convert(0));
		//_delay_ms(200);
		
		break;
		
		case 3:
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, convert(40));
		_delay_ms(200);
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, convert(-angle));
		_delay_ms(200);
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, convert(0));
		//_delay_ms(200);
		
		break;
		
		case 4:
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, convert(-40));
		_delay_ms(200);
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, convert(-angle));
		_delay_ms(200);
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, convert(0));
		//_delay_ms(200);
		
		break;
	}
	_delay_ms(200);
	return DMSDistance(getSensorValue(6));
}


/**
 * Calculates the angle that the legs should move depending on what the sidesensors see.
 * @param distance The distance read from the DMS sensor, should be between 0(10) and 80 cm
 * @return The value to be put into the moving functions determining the length of the steps,
 * the value will be in the interval [0;40]
 */
int getAngle(int distance){
		if(distance < 20) return 0;
		else if(distance < 60) return 15;
		else if(distance < 80) return 20;
		else if(distance < 120) return 30;
		else return 40;
}

/**
 * Convert at number in degrees to a number to give the dynamixel register.
 * @param degree The angle in degrees, can be both positive and negative to control direction
 * @return A number between 0 and 2047 to give the dynamixel registers
 */
unsigned int convert(int degree){
	unsigned int converted;
	if(degree < -60) degree = -60;
	else if(degree > 60) degree = 60;

	converted = (unsigned int)((degree + 150)*3.4);
	return converted;
}



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

	// Define maximum angles for joints (is it needed???)
		
	//dxl_write_word(3, P_CCW_ANGLE_L, 0 );
	//dxl_write_word(3, P_CCW_ANGLE_H, 0 );
	
	sei();	// Interrupt Enable

	// Set default position
	dxl_write_word( BROADCAST_ID, 32, 1023);
	dxl_write_word( HEAD, 32, 511);
	dxl_write_word( BROADCAST_ID, GOAL_POSITION_L, 512 );
	_delay_ms(1000);
}

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

	_delay_ms(200);
	//sprintf("%d\n",getSensorValue(6))
	return DMSDistance(getSensorValue(6));
}


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
 * Calculates the angle that the legs should move if it depending on what the sidesensors see.
 * @param state The state from which the distance was returned
 * @param distance The distance read from the DMSSensor, should be between 0(10) and 80 cm
 * @return The left angle to be put into the moving functions, the value will be in the interval [0;40]
 */
int getAngle(int distance){
		if(distance < 20) return 0;
		else if(distance < 60) return 15;
		else if(distance < 80) return 20;
		else if(distance < 120) return 30;
		else return 40;
}

int getSpeed(int distance){
		if(distance < 30) return 0;
		else return 40;
}


unsigned int convert(int degree){
	unsigned int converted;
	if(degree < -60) degree = -60;
	else if(degree > 60) degree = 60;
	converted = (unsigned int)((degree + 150)*3.4);
	return converted;
}

/**
 * Turns the robot
 * @param direction Direction of turn, either left or right.
 * @param times The number of 45 degree turns made.
 */
//void turn(char direction, char times){
	
	
//}

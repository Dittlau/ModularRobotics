#include <avr/interrupt.h>
#include <util/delay.h>
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

	// Set default position
	dxl_write_word( BROADCAST_ID, GOAL_POSITION_L, 512 );
	_delay_ms(1000);
}

int forward(int state,int direction){
	switch(state){
	case 1:
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, convert(45) );
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, convert(45) );
		/*
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, 400 );
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 300 );
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, 400 );
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 300 );
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, 400 );
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 300 );
		*/
		break;
	case 2:
		convert(60);
		break;

	}
	return 2;
	}

/**
 * Moves the robot forward
 * @param leg The leg to be moved, either front-left, front-right, back-left or back-right.
 * @param direction Direction of movement, either forward or back.
 * @param length The length of movement.
 * @param speed The speed of movement.
 */
void move(int leg, int angle, int length, int speed){
	if (leg==FRONT_LEFT){
		
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 300 );
		_delay_ms(1000);
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, 400 );
		_delay_ms(1000);
		dxl_write_word(FRONT_LEFT_BEND, GOAL_POSITION_L, 512 );
		_delay_ms(2000);
		dxl_write_word(FRONT_LEFT_ROTATE, GOAL_POSITION_L, 700 );
		_delay_ms(1000);
		
		
	}
	else if (leg==FRONT_RIGHT){
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, 300 );
		_delay_ms(1000);
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, 400 );
		_delay_ms(1000);
		dxl_write_word(FRONT_RIGHT_BEND, GOAL_POSITION_L, 512 );
		_delay_ms(2000);
		dxl_write_word(FRONT_RIGHT_ROTATE, GOAL_POSITION_L, 700 );
		_delay_ms(1000);
	}
	else if (leg==BACK_LEFT){
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, 300 );
		_delay_ms(1000);
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, 400 );
		_delay_ms(1000);
		dxl_write_word(BACK_LEFT_BEND, GOAL_POSITION_L, 512 );
		_delay_ms(2000);
		dxl_write_word(BACK_LEFT_ROTATE, GOAL_POSITION_L, 700 );
		_delay_ms(1000);
	}	
	else if (leg==BACK_RIGHT){
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, 300 );
		_delay_ms(1000);
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, 700 );
		_delay_ms(1000);
		dxl_write_word(BACK_RIGHT_BEND, GOAL_POSITION_L, 512 );
		_delay_ms(2000);
		dxl_write_word(BACK_RIGHT_ROTATE, GOAL_POSITION_L, 400 );
		_delay_ms(1000);
	}	
}

int convert(int degree){
	if(degree < -60) degree = -60;
	else if(degree > 60) degree = 60;
	int converted = (degree + 150)*1024/300;

	return converted;
}

/**
 * Turns the robot
 * @param direction Direction of turn, either left or right.
 * @param times The number of 45 degree turns made.
 */
//void turn(char direction, char times){
	
	
//}

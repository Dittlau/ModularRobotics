#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "wheel.h"

/**
 * Initializes the dynamixels to be able to control the wheels.
 */
void wheelInit(void){
	dxl_initialize( 0, DEFAULT_BAUDNUM ); // Not using device index
	sei();	// Interrupt Enable
}


/**
 * Makes a dynamixel spin with a given speed. The dynamixel need to be in wheel-mode.
 * @param id The id of the dynamixel
 * @param speed The speed given as a percentage of maximum speed.
 * Positive percentage will move the motor CCW and negative will move the motor CW.
 */
void wheel(int id, int speed){
	// No angle limitations
	dxl_write_word( id, P_CCW_ANGLE_L, 0 );
	dxl_write_word( id, P_CCW_ANGLE_H, 0 );
	// Setting speed
	dxl_write_word( id, P_SPEED_L, convertSpeed(speed) );
}

/**
 * Converts the speed to a byte
 * @param speedpercentage The speed given in percentage from 10-100. Positive percentage will move the motor CCW and negative will move the motor CW.
 */
int convertSpeed(int speed_percentage){
	int speed=0;
	if(speed_percentage >= 0 && speed_percentage <= 100) speed = (int)(10.23*speed_percentage);
	else if(speed_percentage < 0 && speed_percentage >= -100) speed = (int)(-10.23*speed_percentage)+1024;
	else if(speed_percentage > 100) speed = 100;
	else if(speed_percentage < -100) speed = -100;
	return speed;
}

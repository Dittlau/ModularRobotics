#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "wheel.h"
#include "rotator.h"


/**
 * The main function used to control the gameplay for the robot toy.
 */
int main(){
	int rotating = 0;
	int rotating_prev1 = 0;
	int rotating_prev2 = 0;
	int start = 0;
	int speed = 20;
	int rotator_speed = 15;
	int level = 0;
	int count = 20;
	int jump = 0;
	int active1 = 0;
	int active2 = 0;
	int active3 = 0;
	int active4 = 0;
	int blocks = 0;

	serial_initialize(57600);
	wheelInit();
	ADCInit();
	deactivateBarrier(MOTOR1,speed);
	deactivateBarrier(MOTOR2,speed);
	deactivateBarrier(MOTOR3,speed);
	deactivateBarrier(MOTOR4,speed);

	// Setting all LEDs to output
	DDRC |= 0x7F;
	while(1){

		// Waiting for start-signal
		while(!start){
			start = START;
			if(start){
				_delay_ms(3000);
				wheel(2,rotator_speed);
				_delay_ms(1000);
				rotating = dxl_read_byte(2,38);
				blocks = 0;
			}
		}

		// Playing
		while(blocks < 3){
			jump++;
			if(jump >= 15){
				jump = 0;
				rotating = dxl_read_byte(2,38); // present speed
				if(!rotating){
					blocks++;
					if(blocks > 2){
						printf("blocks: %d\n",blocks);
						wheel(2,0);
						_delay_ms(250);
						start = 0;
						blinkLEDs();
						deactivateBarrier(MOTOR1,speed);
						deactivateBarrier(MOTOR2,speed);
						deactivateBarrier(MOTOR3,speed);
						deactivateBarrier(MOTOR4,speed);
						speed = 20;
						level = 0;
						count = 20;
						rotator_speed = 15;
						active1 = 0;
						active2 = 0;
						active3 = 0;
						active4 = 0;
					}
				}else{
					blocks = 0;
					printf("Blocks resets\n");
				}
			}

			if(count > 20){
				count = 0;
				level++;
				switch(level){
				case 1:
					LED1_ON;
					speed = 20;
					rotator_speed = 15;
					wheel(2,rotator_speed);
					break;
				case 2:
					LED2_ON;
					speed = 45;
					rotator_speed = -17;
					wheel(2,rotator_speed);
					break;
				case 3:
					LED3_ON;
					speed = 70;
					rotator_speed = 19;
					wheel(2,rotator_speed);
					break;
				case 4:
					LED4_ON;
					speed = 95;
					rotator_speed = -21;
					wheel(2,rotator_speed);
					break;
				case 5:
					LED5_ON;
					speed = 120;
					rotator_speed = 23;
					wheel(2,rotator_speed);
					break;
				case 6:
					LED6_ON;
					speed = 145;
					rotator_speed = -25;
					wheel(2,rotator_speed);
					break;
				case 7:
					speed = 1;
					rotator_speed = 1;
					wheel(2,rotator_speed);
					break;
				}
			}
			if(ready(MOTOR1)){
				activateBarrier(MOTOR1,speed);
				active1 = 1;
			}
			if(ready(MOTOR2)){
				activateBarrier(MOTOR2,speed);
				active2 = 1;
			}
			if(ready(MOTOR3)){
				activateBarrier(MOTOR3,speed);
				active3 = 1;
			}
			if(ready(MOTOR4)){
				activateBarrier(MOTOR4,speed);
				active4 = 1;
			}
			if(touch(getSensorValue(6)) && active1){
				deactivateBarrier(MOTOR1,speed);
				active1 = 0;
				count++;
			}
			if(touch(getSensorValue(2)) && active2){
				deactivateBarrier(MOTOR2,speed);
				active2 = 0;
				count++;
			}
			if(touch(getSensorValue(3)) && active3){
				deactivateBarrier(MOTOR3,speed);
				active3 = 0;
				count++;
			}
			if(touch(getSensorValue(4)) && active4){
				deactivateBarrier(MOTOR4,speed);
				active4 = 0;
				count++;
			}


		}

	}
	return 0;
}





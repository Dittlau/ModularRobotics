/*
 * main.c
 *
 * Created: 12-06-2012 15:19:35
 *  Author: cello
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "serial.h"
#include "dynamixel.h"
#include "legs.h"
#include "zig.h"
///
//unsigned char incoming = 0;

int main(void)
{
	int state = 2;
	int left_angle = 40;
	int right_angle = 40;
	
	serial_initialize(57600);
	ADCInit();
	zigbee_initialize();
	//dxl_initialize( 0, 1 );
	sei();
	legsInit();

	//dxl_write_word(9,GOAL_POSITION_L,convert(10));
	
	//printf("%d\n",convert(45));
	unsigned char incoming;

	// Ready position
	forward(1,left_angle,right_angle);
	while(1)
	{
		if (serial_get_qstate()) {
			incoming = serial_get_queue();
		}		
		
		if(incoming == 'w'){
			left_angle = 40;
			right_angle = 40;
			forward(state,left_angle,right_angle);
			state++;
		}
		else if(incoming == 'z'){
			left_angle = 40;
			right_angle = 40;
			forward(5-state,left_angle,right_angle);
			state++;
		}
		else if(incoming == 's'){
			left_angle = 40;
			right_angle = 40;
			forward(1,left_angle,right_angle);
			state = 2;
		}
		else if(incoming == 'q'){   //left forward
			//if(right_angle < 40) right_angle = increase(right_angle);
			//else left_angle = decrease(left_angle);
			left_angle = 10;
			right_angle = 40;
			forward(state,left_angle,right_angle);
			state++;
		}
	    else if(incoming == 'e'){   //right forward
			//if(left_angle < 40) left_angle = increase(left_angle);
			//else right_angle = decrease(right_angle);
	    	left_angle = 40;
	    	right_angle = 10;
			forward(state,left_angle,right_angle);
			state++;
		}
	    else if(incoming == 'a'){   //right forward
			turn(state,40);
			state++;
		}
	    else if(incoming == 'd'){   //right forward
			turn(state,-40);
			state++;
		}

		/*if(incoming != NULL){
			printf("FORWARD  \n");
			forward(state,left_angle,right_angle);
			state++;
		}*/
		printf("%d   %d\n",left_angle,right_angle);
		if(state > 4) state = 1;
	
	}

	return 0;
}

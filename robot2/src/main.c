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
unsigned char incoming = 0;

int main(void)
{
	int state = 1;
	int left_angle, right_angle;
	
	serial_initialize(57600);
	zigbee_initialize();
	//dxl_initialize( 0, 1 );
	sei();
	legsInit();

	//dxl_write_word(8,GOAL_POSITION_L,convert(10))
	
	//printf("%d\n",convert(45));
	unsigned char incoming;
	
	while(1)
	{
		if (serial_get_qstate()) {
		incoming = serial_get_queue();
		}		
		
		//printf("%d\n",serial_get_queue());
		//forward(state,40,20);
		////forward(5-state,40,40);//backwards
		//state++;
		//if(state > 4) state = 1;
		//printf("%d\n",incoming);
		//incoming = getchar();
		
		
		//if(incoming == 'w'){
			//left_angle = 40; 
			//right_angle = 40;
		//forward(state,left_angle,right_angle);
		//state++;	
		//}			
		//else if(incoming == 'e'){   //left forward
		//if(left_angle<40) left_angle += 10;
		//else right_angle -= 10;	
	    //forward(state,left_angle,right_angle);
		//state++;
		//}
		//else if(incoming == 'q'){   //left forward
		//if(right_angle<40) right_angle += 10;
		//else left_angle -= 10;
		//forward(state,left_angle,right_angle);
		//state++;
		//
		//state++;
		//}
		
		if(incoming == 'w'){
			left_angle = 40;
			right_angle = 40;

		}
		else if(incoming == 'q'){   //left forward
			incoming = 'o';
			if(right_angle < 40) right_angle = increase(right_angle);
			else left_angle = decrease(left_angle);
			
		}
	    else if(incoming == 'e'){   //right forward
			incoming = 'o';
			if(left_angle < 40) left_angle = increase(left_angle);
			else right_angle = decrease(right_angle);
	
		}
		
		if(incoming != NULL){
			forward(state,left_angle,right_angle);
			state++;
			printf("%d   %d \n",left_angle,right_angle);
		}		
				
		if(state > 4) state = 1;
	
	}

	return 0;
}

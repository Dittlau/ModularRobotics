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


int main(void)
{
	int state = 1;
	
	serial_initialize(57600);
	zigbee_initialize();
	//dxl_initialize( 0, 1 );
	sei();
	legsInit();
	unsigned char incoming;

	//dxl_write_word(8,GOAL_POSITION_L,convert(10))
	
	//printf("%d\n",convert(45));
	
	
	while(1)
	{
		forward(state,40,20);
		//forward(5-state,40,40);//backwards
		state++;
		if(state > 4) state = 1;
		
		/*incoming = getchar();
		//printf("%d\n",incoming);
		if(incoming == 'w'){
			forward(state,40,40);
			state++;	
		}			
		else if(incoming == 'q'){   //right forward
			forward(state,20,40);
			state++;
		}else if(incoming == 'e'){   //left forward
			forward(state,40,20);
			state++;
		}
						
		if(state > 4) state = 1;
		*/
	}

	return 0;
}

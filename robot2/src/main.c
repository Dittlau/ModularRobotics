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

#define LINK_PLUGIN 0x80
#define ENABLE_RXD_LINK_PC 0x20
#define ENABLE_RXD_LINK_ZIGBEE 0x40


void serial_set_zigbee();
void serial_set_wire();

///

void serial_set_zigbee() {
  DDRD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC | ENABLE_RXD_LINK_ZIGBEE); //Output on the 3 pins -MAY NOT BE NESSESARY

  PORTD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC); //Deactivate LINK_PLUGIN and ENABLE_RXD_LINK_PC   // no pull up
  PORTD |= ENABLE_RXD_LINK_ZIGBEE; //Activate ENABLE_RXD_LINK_ZIGBEE
}

void serial_set_wire() {
  DDRD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC | ENABLE_RXD_LINK_ZIGBEE); //-MAY NOT BE NESSESARY
  
  PORTD &= ~(ENABLE_RXD_LINK_ZIGBEE); //Deactivate ENABLE_RXD_LINK_ZIGBEE
  PORTD |= LINK_PLUGIN | ENABLE_RXD_LINK_PC; //Activate ENABLE_RXD_LINK_PC
}


int main(void)
{
	int state = 1;
	
	serial_initialize(57600);
	serial_set_zigbee();
	//dxl_initialize( 0, 1 );
	sei();
	legsInit();
	unsigned char incoming;

	//dxl_write_word(8,GOAL_POSITION_L,convert(10))
	
	printf("%d\n",convert(45));
	
	
	while(1)
	{
		forward(state,40,40);
		state++;
		if(state > 4) state = 1;
		//incoming = getchar();
		//printf("%d\n",incoming);
		/*if(incoming == 'w'){
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
						
		if(state > 4) state = 1;*/
		
	}

	return 0;
}


/*
// ZIGBEE STUFF

#define LINK_PLUGIN 0x80
#define ENABLE_RXD_LINK_PC 0x20
#define ENABLE_RXD_LINK_ZIGBEE 0x40


	int RcvData;
	
	PORTD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC); //Deactivate LINK_PLUGIN and ENABLE_RXD_LINK_PC   // no pull up
	PORTD |= ENABLE_RXD_LINK_ZIGBEE; //Activate ENABLE_RXD_LINK_ZIGBEE
	//PORTD &= ~(ENABLE_RXD_LINK_ZIGBEE); //Deactivate ENABLE_RXD_LINK_ZIGBEE
	//PORTD |= LINK_PLUGIN | ENABLE_RXD_LINK_PC; //Activate ENABLE_RXD_LINK_PC

	sei();	// Interrupt Enable
	
	while(1)
	{
		printf("Carrot cake");
	}
*/

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

	
	serial_initialize(57600);
	serial_set_zigbee();
	//dxl_initialize( 0, 1 );
	sei();
	
	
	
	while(1)
	{
		unsigned char incoming = getchar();
		if(incoming == 'w'){
			printf("You entered w");
		dxl_write_word( 8, 30, 1023 );	
		}
		
		else{
		printf("You entered z");
		dxl_write_word( 8, 30, 10);		
		//printf("%d\r\n", );
	}

	return 0;
}
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

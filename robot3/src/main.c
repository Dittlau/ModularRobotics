/*
 * Robot_3.c
 *
 * Created: 05-06-2012 18:57:21
 *  Author: Daniel
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#include "serial.h"

#define LINK_PLUGIN 0x80
#define ENABLE_RXD_LINK_PC 0x20
#define ENABLE_RXD_LINK_ZIGBEE 0x40


void serial_set_zigbee();
void serial_set_wire();

///

void serial_set_zigbee() {

  //Output on the 3 pins -MAY NOT BE NESSESARY
  //DDRD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC | ENABLE_RXD_LINK_ZIGBEE);

  PORTD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC); //Deactivate LINK_PLUGIN and ENABLE_RXD_LINK_PC   // no pull up
  PORTD |= ENABLE_RXD_LINK_ZIGBEE; //Activate ENABLE_RXD_LINK_ZIGBEE

}

void serial_set_wire() {
  //-MAY NOT BE NESSESARY
  //DDRD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC | ENABLE_RXD_LINK_ZIGBEE);
  
  PORTD &= ~(ENABLE_RXD_LINK_ZIGBEE); //Deactivate ENABLE_RXD_LINK_ZIGBEE
  PORTD |= LINK_PLUGIN | ENABLE_RXD_LINK_PC; //Activate ENABLE_RXD_LINK_PC
}


int main(void)
{
	serial_set_zigbee();
	serial_set_wire();
	
	sei();
	
	while(1)
	{
		//	printf("hello");
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

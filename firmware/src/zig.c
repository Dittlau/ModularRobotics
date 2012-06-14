#include <avr/io.h>
#include "zig.h"

//#include <stdio.h>
//#include <avr/interrupt.h>
#include "serial.h"

void zigbee_initialize() {
	DDRD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC | ENABLE_RXD_LINK_ZIGBEE); //Output on the 3 pins -MAY NOT BE NESSESARY

	PORTD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC); //Deactivate LINK_PLUGIN and ENABLE_RXD_LINK_PC   // no pull up
	PORTD |= ENABLE_RXD_LINK_ZIGBEE; //Activate ENABLE_RXD_LINK_ZIGBEE
}

void wire_initialize() {
	DDRD &= ~(LINK_PLUGIN | ENABLE_RXD_LINK_PC | ENABLE_RXD_LINK_ZIGBEE); //-MAY NOT BE NESSESARY
	
	PORTD &= ~(ENABLE_RXD_LINK_ZIGBEE); //Deactivate ENABLE_RXD_LINK_ZIGBEE
	PORTD |= LINK_PLUGIN | ENABLE_RXD_LINK_PC; //Activate ENABLE_RXD_LINK_PC
}
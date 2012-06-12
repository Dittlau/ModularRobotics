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
#include "zig.h"

int main(void)
{
	
	serial_initialize(57600);
	sei();
	serial_set_zigbee();
	
	
	
	while(1)
	{
			printf("hello");
	}

	return 0;
}
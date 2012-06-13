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

int receive = 0;

int main(void)
{
	
	serial_initialize(57600);
	zigbee_initialize();
	sei();
	
	
	while(1)
	{
		//receive = serial_read();
		printf("receive");
	}

	return 0;
}
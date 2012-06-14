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
#include "legs.h"


int main(void)
{
	
	serial_initialize(57600);
	zigbee_initialize();
	sei();
	
	legsInit();
	
	
	while(1)
	{
		move(FRONT_LEFT,300,1,1);
		move(BACK_RIGHT,300,1,1);
	}

	return 0;
}
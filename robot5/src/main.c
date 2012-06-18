#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "legs.h"
#include "wheel.h"

void sing(void);


int main(){
	int state = 2;
	int state_turn = 1;
	int distance, angle;
	int left_angle = 40;
	int right_angle = 40;
	serial_initialize(57600);
	ADCInit();
	legsInit();

	// Ready position
	forward(1,left_angle,right_angle);
	while(1)
	{
		sing();


	}

	return 0;
}

void sing(void){
	wheel(2,200);
	_delay_ms(1000);
	wheel(2,400);
	_delay_ms(1000);
	wheel(2,600);
	_delay_ms(1000);
	wheel(2,800);
	_delay_ms(1000);
}



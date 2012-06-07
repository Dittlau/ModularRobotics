#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"

int main(){
	int val;
	serial_initialize(57600);
	ADCInit();

	while(1){
		val = touch(getSensorValue(3));
		printf("%d\n\n",val);
		_delay_ms(10000);
	}

	return 0;
}




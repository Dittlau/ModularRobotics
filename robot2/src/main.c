#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"

int main(){
	int val;
	serial_initialize(57600);
	//ADCInit(1);
	val = 10;//ADCConvert();
	printf("%d\n\n",val);
	return 0;
}




#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"

int main(){
	serial_initialize();
	printf("TESTING");
	return 0;
}




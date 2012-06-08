#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "adc.h"
#include "dxl_hal.h"
#include "dynamixel.h"
#include "wheel.h"



int main(){
	wheelInit();
	wheel(2,50);
	//wheel(1,-50);

	_delay_ms(10000);

	wheel(2,0);
	//wheel(1,0);

	while(1)
	{


	}


	//while(1){
		//val3 = touch(getSensorValue(3));
		//val3 = DMSDistance(getSensorValue(3));
		//printf("%d\n\n",val3);
		//_delay_ms(10000);
	//}

	return 0;
}





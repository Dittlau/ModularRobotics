
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/**
 * Initializes the ADC
 */
void ADCInit(void){
	DDRA  = 0xFC; // All sensors are set as input
	PORTA = 0xFC;
	// Enable ADC and setting division factor to 64
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);

}

/**
 * Gets the value from a sensor, can be both IR-sensor, DMS-sensor and touch-sensor
 * @param port_no The port-number that the sensor is connected to.
 * The values can be found on the Hardware Port Map and should be in the interval [1;7]
 * @return Returns a integer number between 0 and 1023, which is the sensor value
 */
int getSensorValue(int port_no){
	ADMUX = port_no;
	// Setting the chosen sensor port to zero (enable)
	switch(port_no){
	case 1:
		PORTA &= ~0x80;
		break;
	case 2:
		PORTA &= ~0x40;
		break;
	case 3:
		PORTA &= ~0x20;
		break;
	case 4:
		PORTA &= ~0x10;
		break;
	case 5:
		PORTA &= ~0x08;
		break;
	case 6:
		PORTA &= ~0x04;
		break;
	}

	_delay_us(12); // Short Delay for rising sensor signal
	ADCSRA |= (1 << ADIF); // AD-Conversion Interrupt Flag Clear
	ADCSRA |= (1 << ADSC); // AD-Conversion Start

	while( !(ADCSRA & (1 << ADIF)) ); // Wait until AD-Conversion complete
	PORTA = 0xFC;

	return ADC;
}

/**
 * Converts the value from the IR-sensor to a distance given in cm
 * @param sensor_value The value from the IR-sensor
 * @return Returns the distance in cm
 */
int IRDistance(int sensor_value){
	int dist;
	if(sensor_value > 150) dist = (int)(-0.0174*sensor_value + 7);
	if(sensor_value > 40) dist = (int)(-0.04*sensor_value + 10);
	else dist = (int)(-0.1905*sensor_value + 15);
	return dist;
}

int IRValue(int sensor_value){
	if(sensor_value > 25) return 2; // limit was 100 before
	else if(sensor_value > 0) return 1;
	else return 0;
}

/**
 * Converts the value from the DMS-sensor to a distance given in cm
 * @param sensor_value The value from the DMS-sensor
 * @return Returns the distance in cm
 */
int DMSDistance(int sensor_value){
	int dist;
	if(sensor_value > 200) dist = (int)(-0.0345*sensor_value + 30);
	else if(sensor_value > 120) dist = (int)(-0.25*sensor_value + 72);
	else dist = 80;//(int)(-0.7347*sensor_value + 130.2);

	return dist;
}

int DMSValue(int sensor_value){
	if(sensor_value > 200) return 0;
	else if(sensor_value > 120) return 1;
	else return 2;
}
/**
 * Determines if the touch-sensor is on or off
 * @param sensor_value The value from the touch-sensor
 * @return Returns 1 if the touch-sensor is on and 0 if the touch-sensor is off
 */
int touch(int sensor_value){
	if(sensor_value == 0) return 0;
	else return 1;

}

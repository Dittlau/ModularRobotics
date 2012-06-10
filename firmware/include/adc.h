/*
 * adc.h
 *
 *  Created on: 06/06/2012
 *      Author: Kinna
 */

#ifndef ADC_H_
#define ADC_H_


void ADCInit(void);
int getSensorValue(int port_no);
int IRDistance(int sensor_value);
int DMSDistance(int sensor_value);
int touch(int sensor_value);

#endif /* ADC_H_ */

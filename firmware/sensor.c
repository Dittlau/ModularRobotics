/*
 * sensor.c
 *
 *  Created on: 07/06/2012
 *      Author: Kinna
 */

/**
 * Converts the value from an IR sensor to cm
 * @param sensor_value The value returned from the sensor
 * @return The distance in cm
 */
int getIRDistance(int sensor_value){
	int dist;
	// Using equation for line y = ax + b <=> x = (y-b)/a
	if(sensor_value > 300) dist = (sensor_value-828)/(-132);
	else if(sensor_value > 220) dist = (sensor_value-620)/(-80);
	else if(sensor_value > 110) dist = (sensor_value-440)/(-44);
	else if(sensor_value > 60) dist = (sensor_value-260)/(-20);
	else dist = (sensor_value-160)/(-10);
	return dist;
}

/**
 * Converts the value from a DMS sensor to cm
 * @param sensor_value The value returned from the sensor
 * @return The distance in cm
 */
int getDMSDistance(int sensor_value){
	int dist;
	// Using equation for line y = ax + b <=> x = (y-b)/a
	if(sensor_value > 300) dist = (sensor_value-828)/(-132);
	else if(sensor_value > 220) dist = (sensor_value-620)/(-80);
	else if(sensor_value > 110) dist = (sensor_value-440)/(-44);
	else if(sensor_value > 60) dist = (sensor_value-260)/(-20);
	else dist = (sensor_value-160)/(-10);
	return dist;
}

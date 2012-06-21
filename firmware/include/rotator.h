/*
 * rotator.h
 *
 *  Created on: 19/06/2012
 *      Author: Kinna
 */

#ifndef ROTATOR_H_
#define ROTATOR_H_

#define START !(PIND & (1 << 0))

#define MOTOR1	8
#define MOTOR2	4
#define MOTOR3	9
#define MOTOR4	6

#define LED1_ON (PORTC &= ~(1 << 4))
#define LED1_OFF (PORTC |= (1 << 4))
#define LED2_ON (PORTC &= ~(1 << 5))
#define LED2_OFF (PORTC |= (1 << 5))
#define LED3_ON (PORTC &= ~(1 << 6))
#define LED3_OFF (PORTC |= (1 << 6))
#define LED4_ON (PORTC &= ~(1 << 1))
#define LED4_OFF (PORTC |= (1 << 1))
#define LED5_ON (PORTC &= ~(1 << 2))
#define LED5_OFF (PORTC |= (1 << 2))
#define LED6_ON (PORTC &= ~(1 << 3))
#define LED6_OFF (PORTC |= (1 << 3))

#define GOAL_POSITION_L		30
#define MOVING_SPEED_L		32
#define MOVING				46 // is zero when goal is completed

void blinkLEDs(void);
void activateBarrier(int id, int speed);
void deactivateBarrier(int id, int speed);
int ready(int id);
unsigned int convert(int degree);

#endif /* ROTATOR_H_ */

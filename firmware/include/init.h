/*
 * init.h
 *
 * Created: 05-06-2012 20:52:34
 *  Author: Daniel
 */ 

#ifndef INIT_H
#define INIT_H

#ifndef F_CPU
#define F_CPU
#define F_CPU 16000000UL // 16 MHz
#endif /* F_CPU */

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Define buttons
#define START !(PIND & (1 << 0)) // (PIND & 1)
#define BTN_UP !(PINE & (1 << 4))
#define BTN_DOWN !(PINE & (1 << 5))
#define BTN_LEFT !(PINE & (1 << 6))
#define BTN_RIGHT !(PINE & (1 << 7))

// Define LEDs
//#define LEDON_TXD PORTC &= ~(1 << 1)
//#define LEDON_RXD PORTC &= ~(1 << 2)
//#define LEDON_AUX PORTC &= ~(1 << 3)
#define LEDON_MANAGE (PORTC &= ~(1 << 4))
//#define LEDON_PROGRAM PORTC &= ~(1 << 5)
//#define LEDON_PLAY PORTC &= ~(1 << 6)
//#define LEDOFF_TXD PORTC |= 1 << 1
//#define LEDOFF_RXD PORTC |= 1 << 2
//#define LEDOFF_AUX PORTC |= 1 << 3
#define LEDOFF_MANAGE (PORTC |= (1 << 4))
//#define LEDOFF_PROGRAM PORTC |= 1 << 5
//#define LEDOFF_PLAY PORTC |= 1 << 6

void portInit(void);
void adcInit(void);
void timerInit(void);


#endif /* INIT_H_ */
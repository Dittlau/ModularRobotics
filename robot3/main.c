/*
 * Robot_3.c
 *
 * Created: 05-06-2012 18:57:21
 *  Author: Daniel
 */ 

#include "init.h"
#include <avr/interrupt.h>
#include "serial.h"
#include "dynamixel.h"
#include "dxl_hal.h"

unsigned int time=0;
unsigned char data=0;
ISR(TIMER1_COMPA_vect){
	time += 1; //adds 1 to time
	TCNT1 = 0; // resets timer
}

ISR(USART0_RX_vect) {
	data = UDR0;
	
}

#define P_GOAL_POSITION_L		30
#define P_GOAL_POSITION_H		31
#define P_PRESENT_POSITION_L	36
#define P_PRESENT_POSITION_H	37
#define P_MOVING				46

// Defulat setting
#define DEFAULT_BAUDNUM		1 // 1Mbps
#define DEFAULT_ID			1

void PrintCommStatus(int CommStatus);
void PrintErrorCode(void);


int main(){
	//portInit();
	//serial_initialize(57600);
	//dxl_initialize( 0, 1 ); // init with baud = 1 Mbps
	////timerInit();
	////adcInit();
	//sei(); //Enables global interrupts

	unsigned short GoalPos[2] = {0, 1023};
	//unsigned short GoalPos[2] = {0, 4095}; // for EX series
	int index = 0;
	int id = 1;
	int bMoving, wPresentPos;
	int CommStatus;

	serial_initialize(57600);
	dxl_initialize( 0, 1 ); // Not using device index
	sei();	// Interrupt Enable	
	
	printf( "\n\nRead/Write example for CM-510\n\n" );



	while(1) {
	
	// Check moving done
	bMoving = dxl_read_byte( id, P_MOVING );
	CommStatus = dxl_get_result();
	if( CommStatus == COMM_RXSUCCESS )
	{
		if( bMoving == 0 )
		{
			// Change goal position
			if( index == 0 )
			index = 1;
			else
			index = 0;

			// Write goal position
			dxl_write_word( id, P_GOAL_POSITION_L, GoalPos[index] );
		}
		
		PrintErrorCode();
		
		// Read present position
		wPresentPos = dxl_read_word( id, P_PRESENT_POSITION_L );
		printf( "%d   %d\n",GoalPos[index], wPresentPos );
		
	}		
	
	
	
	//PORTA &= ~0x80;			// ADC Port 1 IR ON
	//LEDON_MANAGE;
	//printf("Running time: %d ms\n",time);
	//ADCSRA |= (1 << ADIF);		// AD-Conversion Interrupt Flag Clear
	//ADCSRA |= (1 << ADSC);		// AD-Conversion Start
	//while( !(ADCSRA & (1 << ADIF)) );
	//PORTA = 0xFC;
	//
	//LEDOFF_MANAGE;
	//printf("ADC: %d \n",ADC);
	//_delay_ms(500);		
	}

	return 0;
}

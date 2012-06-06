#define F_CPU 16000000UL // 16 MHz
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect){
	OCR1A += 124; //additional 1 ms for next interrupt
}

void timer_init() {
	TCCR1B = (1<<CS11)|(1<<CS10); //64 Prescaler
	OCR1A = 124; //Equals delay 1 ms
	TIMSK1 = (1<<OCIE1A); //Enable Output Compare Match Interrupt
	TCNT1 = 0; //reset timer/counter 1
	sei(); //Enables global interrupts
}

int main(){
	DDRC = 0b00110001;
	DDRE = 0x00;
	PORTE |= 0b11110000;
	int pushed = 1;


	while(1) {

		if(!(PINE & (1 << 4))){ //checking U-button
			PORTC &= ~(1 << 4); //Set PC0 to low (turn on led)
		}else{
			PORTC |= 1 << 4; //Set PC0 to low (turn on led)
		}

		if(!(PINE & (1 << 7))){ //checking R-button
			//if(pushed == 0){
				PORTC ^= 1<<5 ; //Set PC0 to low (turn on led)
				//pushed = 1;

			//}
				_delay_ms(500); //wait 1000 ms = 1 sec
				//on != on;
		}
		//else{
		//	pushed = 0;
		//}

	}

	return 0;
}




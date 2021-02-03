/*
 * timers.c
 *
 * Created: 2/11/2020 7:23:53 PM
 *  Author: Angel68
 */ 

#include "timers.h"
#include "settings.h"

extern char key_state, key_pressed;

ISR(TIMER1_COMPA_vect){
	if(DEBUG_MODE) PORTB ^= (1<<PB5);
	
	// Magic debouncing algorithm
	static char ct0, ct1;
	char i;
	i = key_state ^ ~KEY_INPUT;
	ct0 = ~(ct0 & i);
	ct1 = ct0 ^ (ct1 & i);
	i &= ct0 & ct1;
	key_state ^= i;
	key_pressed |= key_state & i;
}

void avr_timer_init(){
	OCR1A = TIMER1_OCR1A;
	TIMSK1 |= (1<<OCIE1A);
	TCCR1B |= (1<<WGM12)|(1<<CS12)|(0<<CS11)|(1<<CS10); // CTC mode, clk/1024
	TCCR1A |= (1<<COM1A1)|(0<<COM1A0);
	__asm("sei");
		
	if(DEBUG_MODE) DDRB |= (1<<PB5);
}
/*
 * buttons.c
 *
 * Created: 2/6/2020 10:06:46 PM
 *  Author: Angel68
 */ 

#include "buttons.h"

char key_state, key_pressed;

uint8_t buttons_init(void){
	// Buttons connected to port B	
	DDRB &= ~(BUTTON_PLUS|BUTTON_OK|BUTTON_MINUS); // Output
	PORTB |= BUTTON_PLUS|BUTTON_OK|BUTTON_MINUS; // Pull up resistors enabled
	
	return 0;
}

char get_keypress(char key_mask){
	// Magic debounsing algorithm
	__asm("cli");
	key_mask &= key_pressed;
	key_pressed ^= key_mask;
	__asm("sei");
	return key_mask;
}

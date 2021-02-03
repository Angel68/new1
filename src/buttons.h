/*
 * buttons.h
 *
 * Created: 2/6/2020 10:06:31 PM
 *  Author: Angel68
 */ 

#include <include/stdint.h>
#include <include/avr/io.h>
#include "settings.h"

#define KEY_INPUT ((PINB & 1<<0)|(PINB & 1<<1)|(PINB & 1<<2))

#ifndef BUTTONS_H_
#define BUTTONS_H_

	/*enum BUTTONS {
		BUTTON_PLUS,
		BUTTON_OK,
		BUTTON_MINUS
	};*/
	
#define BUTTON_PLUS (1<<0)
#define BUTTON_OK (1<<1)
#define BUTTON_MINUS (1<<2)

	uint8_t buttons_init(void);
	char get_keypress(char key_mask);

#endif /* BUTTONS_H_ */
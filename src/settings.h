/*
 * settings.h
 *
 * Created: 2/11/2020 7:36:50 PM
 *  Author: Angel68
 */ 

typedef uint8_t (*pModeset)();
pModeset SetMode;

#ifndef SETTINGS_H_
#define SETTINGS_H_

// Debug mode
#define DEBUG_MODE 1 // set to zero after debugging or set to 1 if need to debug

// MCU Settings
#define F_CPU 16000000UL

// I2C Settings
#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

// Timer1 Setting
#define BUTTON_CHECK_FREQ 15
#define TIMER1_PRESCALER 1024 // also need to change 30 line in timers.c
#define TIMER1_OCR1A ((F_CPU / (2 * TIMER1_PRESCALER * BUTTON_CHECK_FREQ)) - 1)

#endif /* SETTINGS_H_ */
#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

avr-gcc -I $DIR -mmcu=atmega328p -Os Smartwatch3.c buttons.c timers.c ds3231.c sh1106.c modes.c i2c.c bcd.c -o $DIR/build/main.o
avr-objcopy -j .text -j .data -O ihex $DIR/build/main.o $DIR/build/main.hex

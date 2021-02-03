/*
 * bcd.c
 *
 * Created: 1/9/2020 4:09:50 PM
 *  Author: Angel68
 */ 

#include "bcd.h"

uint8_t bin2bcd(uint8_t num){	
	uint16_t temp = 0;
	uint16_t temp2 = 0;
	uint8_t x = 0;
	
	temp = num;
	while(x < 8){
		temp2 = (temp&0xF00) >> 8;
		if(temp2 > 4){
			temp2 += 3;
			temp ^= (temp&0xF00);	// clear bits before write
			temp |= (temp2 << 8);
		}
		temp <<= 1;
		x++;
	}
	return temp >>= 8;
}

uint8_t bcd2bin(uint8_t num){
	uint8_t temp = 0;
	
	temp = ((((num&0xF0)>>4)*10)+(num&0xF));
	return temp;
}
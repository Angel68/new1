/*
 * bcd.h
 *
 * Created: 1/9/2020 4:09:00 PM
 *  Author: Angel68
 */ 

#include <include/stdint.h>

#ifndef BCD_H_
#define BCD_H_
	
	uint8_t bin2bcd(uint8_t num);
	uint8_t bcd2bin(uint8_t num);
	
#endif /* BCD_H_ */
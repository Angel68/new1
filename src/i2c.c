/*
 * i2c.c
 *
 * Created: 1/9/2020 3:14:46 PM
 *  Author: Angel68
 */ 

#include <i2c.h>

void i2c_init(void){
	TWBR = (uint8_t)TWBR_val;
}

uint8_t i2c_start(uint8_t address){
	TWCR = 0; // reset TWI control register
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); // transmit START condition
	while(!(TWCR & (1<<TWINT))); // wait for end of transmission
	if((TWSR & 0xF8) != TW_START){ return 1; } // check if the start condition was successfully transmitted
	TWDR = address; // load slave address into data register
	TWCR = (1<<TWINT) | (1<<TWEN); // start transmission of address
	while(!(TWCR & (1<<TWINT))); // wait for end of transmission
	uint8_t twst = TW_STATUS & 0xF8; // check if the device has acknowledged the READ / WRITE mode
	if ((twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK)) return 1;
	return 0;
}

uint8_t i2c_write(uint8_t data){	
	TWDR = data; // load data into data register
	TWCR = (1<<TWINT) | (1<<TWEN); // start transmission of data
	while(!(TWCR & (1<<TWINT))); // wait for end of transmission
	if((TWSR & 0xF8) != TW_MT_DATA_ACK){ return 1; }
	return 0;
}

uint8_t i2c_read_ack(void){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); // start TWI module and acknowledge data after reception
	while(!(TWCR & (1<<TWINT))); // wait for end of transmission
	return TWDR; // return received data from TWDR
}

uint8_t i2c_read_nack(void){
	TWCR = (1<<TWINT) | (1<<TWEN); // start receiving without acknowledging reception
	while(!(TWCR & (1<<TWINT))); // wait for end of transmission
	return TWDR; // return received data from TWDR
}

uint8_t i2c_transmit(uint8_t address, uint8_t* data, uint16_t length){
	if (i2c_start(address | I2C_WRITE)) return 1;
	for (uint16_t i = 0; i < length; i++){
		if (i2c_write(data[i])) return 1;
	}
	i2c_stop();
	return 0;
}

uint8_t i2c_receive(uint8_t address, uint8_t* data, uint16_t length){
	if (i2c_start(address | I2C_READ)) return 1;	
	for (uint16_t i = 0; i < (length-1); i++){
		data[i] = i2c_read_ack();
	}
	data[(length-1)] = i2c_read_nack();	
	i2c_stop();	
	return 0;
}

uint8_t i2c_writeReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length){
	if (i2c_start(devaddr | 0x00)) return 1;
	i2c_write(regaddr);
	for (uint16_t i = 0; i < length; i++){
		if (i2c_write(data[i])) return 1;
	}
	i2c_stop();
	return 0;
}

uint8_t i2c_readReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length){
	if (i2c_start(devaddr)) return 1;
	i2c_write(regaddr);
	if (i2c_start(devaddr | 0x01)) return 1;
	for (uint16_t i = 0; i < (length-1); i++){
		data[i] = i2c_read_ack();
	}
	data[(length-1)] = i2c_read_nack();
	i2c_stop();
	return 0;
}

void i2c_stop(void){	
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO); // transmit STOP condition
}
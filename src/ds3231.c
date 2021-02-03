/*
 * ds3231.c
 *
 * Created: 1/22/2020 4:09:25 PM
 *  Author: Angel68
 */ 

#include <ds3231.h>

uint8_t ds3231_init(void){
	if(i2c_start(DS3231_I2C_READ)){
		i2c_stop();
		return 1;
	}
	i2c_stop();
	return 0;
}

// Seconds comes packed in one byte (hex) -------------- OBSOLETE ---- TO REMOVE -----
/*
uint8_t ds3231_read_all(void){
	if(i2c_start(DS3231_I2C_WRITE)){ return 1; }
	i2c_write(0x00);
	i2c_stop();
	
	if(i2c_start(DS3231_I2C_READ)){ return 1; }
	
	Time.seconds	    = i2c_read_ack();
	Time.minutes	    = i2c_read_ack();
	Time.hours		    = i2c_read_ack();
	Time.day_of_week    = i2c_read_ack();
	Time.date		    = i2c_read_ack();
	Time.month		    = i2c_read_ack();
	Time.year		    = i2c_read_ack();
	Time.alarm1_seconds = i2c_read_ack();
	Time.alarm1_minutes = i2c_read_ack();
	Time.alarm1_hours	= i2c_read_ack();
	Time.alarm1_day		= i2c_read_ack();
	Time.alarm2_seconds = i2c_read_ack();
	Time.alarm2_minutes = i2c_read_ack();
	Time.alarm2_hours	= i2c_read_ack();
	Time.alarm2_day		= i2c_read_ack();
	Time.control		= i2c_read_ack();
	Time.status			= i2c_read_ack();
	Time.aging_offset	= i2c_read_ack();
	Time.temperatureMSB = i2c_read_ack();
	Time.temperatureLSB = i2c_read_ack();
	i2c_stop();
	return 0;
}*/
//---------------------------------------------------------- END OF OBSOLETE -----------

uint8_t ds3231_read(enum ds3231reg address){
	if(i2c_start(DS3231_I2C_WRITE)){ return 1; }

	switch(address){
		case DS_TIME:	i2c_write(0x00); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }
						Time.seconds = i2c_read_ack();
						Time.minutes = i2c_read_ack();
						Time.hours   = i2c_read_ack();
						i2c_stop();
						break;
		
		case DS_DATE:	i2c_write(0x03); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }
						Time.day_of_week    = i2c_read_ack();
						Time.date		    = i2c_read_ack();
						Time.month		    = i2c_read_ack();
						Time.year		    = i2c_read_ack();
						i2c_stop();
						break;
		
		case DS_ALARM1:	i2c_write(0x07); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }
						Time.alarm1_seconds = i2c_read_ack();
						Time.alarm1_minutes = i2c_read_ack();
						Time.alarm1_hours	= i2c_read_ack();
						Time.alarm1_day		= i2c_read_ack();
						i2c_stop();
						break;
						
		case DS_ALARM2:	i2c_write(0x0B); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }
						Time.alarm2_seconds = i2c_read_ack();
						Time.alarm2_minutes = i2c_read_ack();
						Time.alarm2_hours	= i2c_read_ack();
						Time.alarm2_day		= i2c_read_ack();
						i2c_stop();
						break;
						
		case DS_CONTROL:i2c_write(0x0E); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }
						Time.control = i2c_read_ack();
						i2c_stop();
						break;
						
		case DS_STATUS: i2c_write(0x0F); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }
						Time.status = i2c_read_ack();
						i2c_stop();
						break;
						
		case DS_TEMPERATURE: i2c_write(0x11); i2c_stop();
							 if(i2c_start(DS3231_I2C_READ)){ return 1; }
							 Time.temperatureMSB = i2c_read_ack();
							 Time.temperatureLSB = i2c_read_ack();
							 i2c_stop();
							 break;
							 
		case DS_ALL:	i2c_write(0x00); i2c_stop();
						if(i2c_start(DS3231_I2C_READ)){ return 1; }						
						
						Time.seconds	    = i2c_read_ack();
						Time.minutes	    = i2c_read_ack();
						Time.hours		    = i2c_read_ack();
						Time.day_of_week    = i2c_read_ack();
						Time.date		    = i2c_read_ack();
						Time.month		    = i2c_read_ack();
						Time.year		    = i2c_read_ack();
						Time.alarm1_seconds = i2c_read_ack();
						Time.alarm1_minutes = i2c_read_ack();
						Time.alarm1_hours	= i2c_read_ack();
						Time.alarm1_day		= i2c_read_ack();
						Time.alarm2_seconds = i2c_read_ack();
						Time.alarm2_minutes = i2c_read_ack();
						Time.alarm2_hours	= i2c_read_ack();
						Time.alarm2_day		= i2c_read_ack();
						Time.control		= i2c_read_ack();
						Time.status			= i2c_read_ack();
						Time.aging_offset	= i2c_read_ack();
						Time.temperatureMSB = i2c_read_ack();
						Time.temperatureLSB = i2c_read_ack();
						i2c_stop();
						break;
								
		default: break;
		}
	return 0;
}

uint8_t	ds3231_write_all(void){
	/*Time.hours		    = bin2bcd(18);
	Time.minutes	    = bin2bcd(49);
	Time.seconds	    = bin2bcd(0);*/
		
	i2c_start(DS3231_I2C_WRITE);
	i2c_write(0x00);
	i2c_write(Time.seconds);
	i2c_write(Time.minutes);
	i2c_write(Time.hours);
	i2c_stop();
	return 0;
}	
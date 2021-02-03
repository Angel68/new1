/*
 * ds3231.h
 *
 * Created: 1/22/2020 4:09:10 PM
 *  Author: Angel68
 */ 

#include <include/stdint.h>
#include <i2c.h>
#include "bcd.h"

#define DS3231_ADDRESS 0x68
#define DS3231_I2C_WRITE        ((DS3231_ADDRESS << 1) + I2C_WRITE)
#define DS3231_I2C_READ         ((DS3231_ADDRESS << 1) + I2C_READ)

#ifndef DS3231_H_
#define DS3231_H_

	enum ds3231reg {
		DS_TIME,
		DS_DATE,
		DS_ALARM1,
		DS_ALARM2,
		DS_CONTROL,
		DS_STATUS,
		DS_TEMPERATURE,
		DS_ALL
	};

	struct ds3231_Time{
		uint8_t seconds;
		uint8_t minutes;
		uint8_t hours;
		uint8_t day_of_week;
		uint8_t date;
		uint8_t month;
		uint8_t year;
		uint8_t alarm1_seconds;
		uint8_t alarm1_minutes;
		uint8_t alarm1_hours;
		uint8_t alarm1_day;
		uint8_t alarm2_seconds;
		uint8_t alarm2_minutes;
		uint8_t alarm2_hours;
		uint8_t alarm2_day;
		uint8_t control;
		uint8_t status;
		uint8_t aging_offset;
		uint8_t temperatureMSB;
		uint8_t temperatureLSB;
	}Time;//*Time;

	uint8_t ds3231_init(void);
	uint8_t	ds3231_read_all(void);
	uint8_t	ds3231_read(enum ds3231reg);

	uint8_t	ds3231_write_all(void);

#endif /* DS3231_H_ */
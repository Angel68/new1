/*
 * modes.h
 *
 * Created: 2/5/2020 7:24:26 PM
 *  Author: Angel68
 */ 

#include <include/stdint.h>
#include "ds3231.h"
#include "sh1106.h"
#include "buttons.h"

#ifndef MODES_H_
#define MODES_H_

	enum mode_types{
		MAIN_SCREEN,
		SETTINGS_SCREEN
	};

	enum change_time_types{
		CHANGE_HOURS,
		CHANGE_MINUTES,
		CHANGE_SECONDS,
		CHANGE_DATE,
		CHANGE_MONTH,
		CHANGE_YEAR,
		CHANGE_DAY_OF_WEEK
	};

	uint8_t main_screen_display(void);
	uint8_t settings_screen_display(void);
	//uint8_t increment_ds3231_value(void);
	uint8_t refresh(uint8_t *pTime_item, enum change_time_types time_type);

#endif /* MODES_H_ */
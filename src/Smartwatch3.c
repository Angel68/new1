/*
 * Smartwatch3.c
 *
 * Created: 1/9/2020 3:11:56 PM
 *  Author: Angel68
 *
 *  Button debouncing algorithm by P.Dannegger danni@specs.de
 */ 

#include <Smartwatch3.h>

extern uint8_t current_mode;
extern uint8_t adjust_time;
uint8_t *pTime_item;

// For debug mode
char b_ok_message[] = "Button OK";
char b_plus_message[] = "Button PLUS ";
char b_minus_message[] = "Button MINUS";

int main(void){
	i2c_init();
	ds3231_read(DS_ALL);
	sh1106_init();
	sh1106_cls();
	buttons_init();
	avr_timer_init();
	
	__asm("sei"); // Enable global interrupts
	
	while(1){
		switch(current_mode){
			case MAIN_SCREEN:		if(get_keypress(BUTTON_OK)){
										sh1106_cls();
										SetMode = &settings_screen_display;
										SetMode(); // execute function
										break;
									}
									SetMode = &main_screen_display;
									SetMode();
									break;
			
			case SETTINGS_SCREEN:	if(get_keypress(BUTTON_OK)){
										current_mode = MAIN_SCREEN;
										adjust_time = 0;
										sh1106_cls();
										ds3231_write_all();
										SetMode = &main_screen_display;
										SetMode();
										break;
									}
			
									if (get_keypress(BUTTON_MINUS)){
										current_mode = SETTINGS_SCREEN;
										if(DEBUG_MODE) { sh1106_cls(); sh1106_print(3, 0, b_minus_message, 12); }
										
										if (adjust_time >= 6){
											adjust_time = 0;
											current_mode = MAIN_SCREEN;
											sh1106_cls();
											SetMode = &main_screen_display;
											SetMode();
											break;
										}
										
										adjust_time++;
										/*SetMode = &settings_screen_display;
										SetMode();*/
										//refresh();
										break;
									}
			
									if (get_keypress(BUTTON_PLUS)){
										//sh1106_cls();
										current_mode = SETTINGS_SCREEN;
										if(DEBUG_MODE) { sh1106_cls(); sh1106_print(3, 0, b_plus_message, 12); }
										
										switch(adjust_time){
											case CHANGE_HOURS:	 refresh(&Time.hours,	CHANGE_HOURS);		break;
											case CHANGE_MINUTES: refresh(&Time.minutes, CHANGE_MINUTES);	break;
											case CHANGE_SECONDS: refresh(&Time.seconds, CHANGE_SECONDS);	break;
											case CHANGE_DATE:	 refresh(&Time.date,	CHANGE_DATE);		break;
											case CHANGE_MONTH:	 refresh(&Time.month,	CHANGE_MONTH);		break;
											case CHANGE_YEAR:	 refresh(&Time.year,	CHANGE_YEAR);		break;
											case CHANGE_DAY_OF_WEEK: refresh(&Time.day_of_week, CHANGE_DAY_OF_WEEK);	break;
											default: break;
										}
										
										
										/*switch(adjust_time){
											case CHANGE_HOURS:	if(Time.hours > 23) { Time.hours = 0; } else { Time.hours++; }
																refresh();
																break;
											case CHANGE_MINUTES:		Time.minutes++;		refresh();	break;
											case CHANGE_SECONDS:		Time.seconds++;		refresh();	break;
											case CHANGE_DATE:			Time.date++;		refresh();	break;
											case CHANGE_MONTH:			Time.month++;		refresh();	break;
											case CHANGE_YEAR:			Time.year++;		refresh();	break;
											case CHANGE_DAY_OF_WEEK:	Time.day_of_week++;	refresh();	break;
											default: break;
										}	*/									
										break;
									}
			
			default: break;
		}
	}
	return 0;
}
/*
 * modes.c
 *
 * Created: 2/5/2020 7:24:44 PM
 *  Author: Angel68
 */ 

#include "modes.h"

#define arr_length(arr) ((sizeof(arr))/(sizeof(arr[0]))-1)

enum mode_types current_mode;
enum change_time_types adjust_time;
uint8_t adjust_time = 0;
uint8_t time;

//char* string = "TODAY IS A GOOD DAY";
char str_main_screen[] = "TODAY IS A GOOD DAY";
char str_settings_screen[] = "SETTINGS";

uint8_t hours[2] = {};
uint8_t minutes[2] = {};
uint8_t seconds[2] = {};
	
uint8_t main_screen_display(void){
	sh1106_print(10, 0, str_main_screen, arr_length(str_main_screen));
	
	ds3231_read(DS_TIME);
	
	hours[0] = ((Time.hours&0xF0)>>4) + 0x30;
	hours[1] = ((Time.hours&0x0F)) + 0x30;
	sh1106_print_big_number(10, 3, (char*)hours);
	
	minutes[0] = ((Time.minutes&0xF0)>>4) + 0x30;
	minutes[1] = ((Time.minutes&0x0F)) + 0x30;
	sh1106_print_big_number(50, 3, (char*)minutes);
	
	seconds[0] = ((Time.seconds&0xF0)>>4) + 0x30;
	seconds[1] = ((Time.seconds&0x0F)) + 0x30;
	sh1106_print_big_number(90, 3, (char*)seconds);
	
	current_mode = MAIN_SCREEN;
	
	return 0;
}

uint8_t settings_screen_display(void){
	sh1106_print(30, 1, str_settings_screen, arr_length(str_settings_screen));
	current_mode = SETTINGS_SCREEN;
	
	hours[0] = ((Time.hours&0xF0)>>4) + 0x30;
	hours[1] = ((Time.hours&0x0F)) + 0x30;
	sh1106_print_big_number(10, 3, (char*)hours);
	
	minutes[0] = ((Time.minutes&0xF0)>>4) + 0x30;
	minutes[1] = ((Time.minutes&0x0F)) + 0x30;
	sh1106_print_big_number(50, 3, (char*)minutes);
	
	seconds[0] = ((Time.seconds&0xF0)>>4) + 0x30;
	seconds[1] = ((Time.seconds&0x0F)) + 0x30;
	sh1106_print_big_number(90, 3, (char*)seconds);
	
	/*adjust_time++;
	if (adjust_time > 6){
		current_mode = MAIN_SCREEN;
		adjust_time = 0;
		SetMode = &main_screen_display;
		SetMode();
	}*/
	return 0;
}

uint8_t refresh(uint8_t *pTime_item, enum change_time_types time_type){
	uint8_t temp = 0;
	
	switch(time_type){
		case CHANGE_HOURS:		temp = bcd2bin(*pTime_item);
								if(temp >= 23) { temp = 0; } else { temp++; }
								*pTime_item = bin2bcd(temp);
								break;

		case CHANGE_MINUTES:	temp = bcd2bin(*pTime_item);
								if(temp >= 59) { temp = 0; } else { temp++; }
								*pTime_item = bin2bcd(temp);
								break;
								
		case CHANGE_SECONDS:	temp = bcd2bin(*pTime_item);
								if(temp >= 59) { temp = 0; } else { temp++; }
								*pTime_item = bin2bcd(temp);
								break;
								
/*		case CHANGE_DATE:			Time.date++;		refresh();	break;
		case CHANGE_MONTH:			Time.month++;		refresh();	break;
		case CHANGE_YEAR:			Time.year++;		refresh();	break;
		case CHANGE_DAY_OF_WEEK:	Time.day_of_week++;	refresh();	break;*/
		default: break;
	}
	
	hours[0] = ((Time.hours&0xF0)>>4) + 0x30;
	hours[1] = ((Time.hours&0x0F)) + 0x30;
	sh1106_print_big_number(10, 3, (char*)hours);
	
	minutes[0] = ((Time.minutes&0xF0)>>4) + 0x30;
	minutes[1] = ((Time.minutes&0x0F)) + 0x30;
	sh1106_print_big_number(50, 3, (char*)minutes);
	
	seconds[0] = ((Time.seconds&0xF0)>>4) + 0x30;
	seconds[1] = ((Time.seconds&0x0F)) + 0x30;
	sh1106_print_big_number(90, 3, (char*)seconds);
	
	return 0;
}

/*
uint8_t refresh(void){
		hours[0] = ((Time.hours&0xF0)>>4) + 0x30;
		hours[1] = ((Time.hours&0x0F)) + 0x30;
		sh1106_print_big_number(10, 3, (char*)hours);
		
		minutes[0] = ((Time.minutes&0xF0)>>4) + 0x30;
		minutes[1] = ((Time.minutes&0x0F)) + 0x30;
		sh1106_print_big_number(50, 3, (char*)minutes);
		
		seconds[0] = ((Time.seconds&0xF0)>>4) + 0x30;
		seconds[1] = ((Time.seconds&0x0F)) + 0x30;
		sh1106_print_big_number(90, 3, (char*)seconds);
		
		return 0;
}*/

/*
uint8_t b_ok(){
	sh1106_cls();
	sh1106_print(10, 0, b_ok_message, arr_length(b_ok_message));
	screen_refresh_lock = 1;
	
	//refresh_screen();
	
	return 0;
}

uint8_t b_plus(){
	//sh1106_cls();
	sh1106_print(10, 0, b_plus_message, arr_length(b_plus_message));
	return 0;
}

uint8_t b_minus(){
	//sh1106_cls();
	sh1106_print(10, 0, b_minus_message, arr_length(b_minus_message));
	return 0;
}

uint8_t refresh_screen(void){
	//sh1106_cls();
	if(!screen_refresh_lock){
		hours[0] = ((Time.hours&0xF0)>>4) + 0x30;
		hours[1] = ((Time.hours&0x0F)) + 0x30;
		sh1106_print_big_number(10, 3, (char*)hours);
	
		minutes[0] = ((Time.minutes&0xF0)>>4) + 0x30;
		minutes[1] = ((Time.minutes&0x0F)) + 0x30;
		sh1106_print_big_number(50, 3, (char*)minutes);
	
		seconds[0] = ((Time.seconds&0xF0)>>4) + 0x30;
		seconds[1] = ((Time.seconds&0x0F)) + 0x30;
		sh1106_print_big_number(90, 3, (char*)seconds);
	}
	return 0;
}
*/

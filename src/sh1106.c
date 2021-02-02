#include "sh1106.h"

uint8_t letter_A[] = {0x00, 0x7C, 0x12, 0x12, 0x7C, 0x00};
uint8_t letter_B[] = {0x00, 0x7E, 0x4A, 0x4A, 0x34, 0x00};
uint8_t letter_C[] = {0x00, 0x3c, 0x42, 0x42, 0x24, 0x00};
uint8_t letter_D[] = {0x00, 0x7e, 0x42, 0x42, 0x3c, 0x00};
uint8_t letter_E[] = {0x00, 0x7e, 0x4a, 0x4a, 0x42, 0x00};
uint8_t letter_F[] = {0x00, 0x7e, 0x0a, 0x0a, 0x02, 0x00};
uint8_t letter_G[] = {0x00, 0x3c, 0x42, 0x62, 0x64, 0x00};
uint8_t letter_H[] = {0x00, 0x7e, 0x08, 0x08, 0x7e, 0x00};
uint8_t letter_I[] = {0x00, 0x00, 0x42, 0x7e, 0x42, 0x00};
uint8_t letter_J[] = {0x00, 0x22, 0x42, 0x3e, 0x02, 0x00};
uint8_t letter_K[] = {0x00, 0x7e, 0x18, 0x24, 0x42, 0x00};
uint8_t letter_L[] = {0x00, 0x7e, 0x40, 0x40, 0x40, 0x00};
uint8_t letter_M[] = {0x00, 0x7e, 0x04, 0x18, 0x04, 0x7e};
uint8_t letter_N[] = {0x00, 0x7e, 0x08, 0x10, 0x7e, 0x00};
uint8_t letter_O[] = {0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00};
uint8_t letter_P[] = {0x00, 0x7e, 0x12, 0x12, 0x0c, 0x00};
uint8_t letter_Q[] = {0x00, 0x3c, 0x42, 0x62, 0x7c, 0x80};
uint8_t letter_R[] = {0x00, 0x7e, 0x12, 0x32, 0x4c, 0x00};
uint8_t letter_S[] = {0x00, 0x24, 0x4a, 0x52, 0x24, 0x00};
uint8_t letter_T[] = {0x00, 0x02, 0x02, 0x7e, 0x02, 0x02};
uint8_t letter_U[] = {0x00, 0x3e, 0x40, 0x40, 0x40, 0x3e};
uint8_t letter_V[] = {0x00, 0x1e, 0x20, 0x40, 0x20, 0x1e};
uint8_t letter_W[] = {0x00, 0x3e, 0x40, 0x30, 0x40, 0x3e};
uint8_t letter_X[] = {0x00, 0x42, 0x24, 0x18, 0x24, 0x42};
uint8_t letter_Y[] = {0x00, 0x06, 0x08, 0x70, 0x08, 0x06};
uint8_t letter_Z[] = {0x00, 0x62, 0x52, 0x4a, 0x46, 0x00};

uint8_t *pLetter[]={letter_A, \
					letter_B, \
					letter_C, \
					letter_D, \
					letter_E, \
					letter_F, \
					letter_G, \
					letter_H, \
					letter_I, \
					letter_J, \
					letter_K, \
					letter_L, \
					letter_M, \
					letter_N, \
					letter_O, \
					letter_P, \
					letter_Q, \
					letter_R, \
					letter_S, \
					letter_T, \
					letter_U, \
					letter_V, \
					letter_W, \
					letter_X, \
					letter_Y, \
					letter_Z};

void sh1106_init(void) {
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(0x00);
	i2c_write(SET_DISPLAY_OFF);
	i2c_write(SET_CLOCK_FREQUENCY);
	i2c_write(0x80);
	i2c_write(SET_MULTIPLEX_RATIO);
	i2c_write(0x3F);
	i2c_write(SET_DISPLAY_OFFSET);
	i2c_write(0x00);
	i2c_write(SET_START_LINE);
	i2c_write(SET_CHARGE_PUMP);
	i2c_write(0x14);
	i2c_write(SET_MEMORY_ADDRESSING_MODE);
	i2c_write(PAGE_ADDRESSING_MODE);
	i2c_write(SET_SEGMENT_REMAP_127_0);
	i2c_write(SET_COM_SCAN_DIRECTION);
	i2c_write(SET_PINS_CONFIGURATION);
	i2c_write(0x12);
	i2c_write(SET_CONTRAST);
	i2c_write(0x01);
	i2c_write(SET_PRECHARGE_PERIOD);
	i2c_write(0xF1);
	i2c_write(SET_VCOM_LEVEL);
	i2c_write(0x40);
	i2c_write(STOP_SCROLL);
	i2c_write(ENTIRE_DISPLAY_ON);
	i2c_write(SET_NORMAL_DISPLAY);
	i2c_write(SET_DISPLAY_ON);
	i2c_stop();
}

void sh1106_cls(void) {
	uint8_t npage, tmp;
	
	for(npage = 0; npage < 8; npage++) {
		i2c_start(SH1106_I2C_WRITE);
		i2c_write(0x00);
		i2c_write(0x10);
		i2c_write(0x02);
		i2c_write(0xB0 + npage);
		i2c_stop();
		
		i2c_start(SH1106_I2C_WRITE);
		i2c_write(0x40);
		for(tmp = 0; tmp < 128; tmp++) {
			i2c_write(0x00);
		}
		i2c_stop();
	}
}

void sh1106_test(void) {
	uint8_t npage, tmp;
	
	while(1) {
		
		for(npage = 0; npage < 8; npage++) {
			i2c_start(SH1106_I2C_WRITE);
			i2c_write(0x00);
			i2c_write(0x10);
			i2c_write(0x02);
			i2c_write(0xB0 + npage);
			i2c_stop();

			i2c_start(SH1106_I2C_WRITE);
			i2c_write(0x40);
			for(tmp = 0; tmp < 128; tmp++) {
				i2c_write(0x00);
				for(uint16_t tt = 0; tt < 30000; tt++){ __asm__("nop"); }
			}
			i2c_stop();
		}
		
		for(npage = 0; npage < 8; npage++) {
			i2c_start(SH1106_I2C_WRITE);
			i2c_write(0x00);
			i2c_write(0x10);
			i2c_write(0x02);
			i2c_write(0xB0 + npage);
			i2c_stop();

			i2c_start(SH1106_I2C_WRITE);
			i2c_write(0x40);
			for(tmp = 0; tmp < 64; tmp++) {
				i2c_write(0xAA);
				i2c_write(0x55);
				//for(uint16_t tt = 0; tt < 255; tt++){ __asm__("nop"); }
			}
			i2c_stop();
		}
	}
}

/*
void sh1106_test2(void){
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(0x00);
	i2c_write(0x10);
	i2c_write(0x02);
	
	i2c_write(0x11);
	
	i2c_write(0xB0);
	i2c_stop();

	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SET_START_LINE);

	for (uint8_t t = 0; t < 3; t++){

		for(uint8_t tmp = 0; tmp < 6; tmp++) {
			i2c_write(letter_a[tmp]);
		}
		for(uint8_t tmp = 0; tmp < 6; tmp++) {
			i2c_write(letter_b[tmp]);
		}
	}
	i2c_stop();
}*/

/*
void sh1106_test3(void){
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_COMMAND);
	
	i2c_write(SET_MEMORY_ADDRESSING_MODE);
	i2c_write(PAGE_ADDRESSING_MODE);
	
	i2c_write(0x02); // Set lower column  [0x00~0x0F]  // Corrected to 0x02 because of view area
	i2c_write(0x10); // Set higher column [0x10~0x1F]
	i2c_write(0xB1); // Set page number   [0xB0~0xB7]
	
	i2c_stop();
	
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_DATA);
	
	for(uint8_t tmp = 0; tmp < 6; tmp++) {
		i2c_write(letter_a[tmp]);
	}	
}*/

void sh1106_transmit(uint8_t x, uint8_t y, uint8_t *data, uint8_t length){
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_COMMAND);
	
	i2c_write(SET_MEMORY_ADDRESSING_MODE);
	i2c_write(PAGE_ADDRESSING_MODE);
	
	i2c_write(0x00|(x&0x0F)); // Set start column lower nimble  [0x00~0x0F]
	i2c_write(0x10|(x>>4));   // Set start column higher nimble [0x10~0x1F]
	
	(y >= 0 && y <= 7) ? i2c_write(0xB0|y) : i2c_write(0xB0); // Set page number   [0xB0~0xB7]
	
	i2c_stop();
	
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_DATA);
	
	for(uint8_t tmp = 0; tmp <= length ; tmp++) {
		i2c_write(*data);
		data++;
	}
}

void sh1106_print(uint8_t x, uint8_t y, uint8_t *string, uint8_t length){
	for(uint8_t tmp = 0; tmp < (length-1); tmp++){
		sh1106_transmit((x+(tmp*6)), y, pLetter[((string[tmp])-0x41)], 6);
	}
}

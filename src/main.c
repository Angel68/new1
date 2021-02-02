#include <avr/io.h>
#include <i2c.h>
#include <bcd.h>
#include <sh1106.h>

// MCU Settings
#define F_CPU 16000000UL

// I2C Settings
#define F_SCL 400000UL // SCL frequency
#define Prescaler 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)

// Other Definitions
#define str_length(str) ((sizeof(str))/(sizeof(str[0]))) 
				
uint8_t string[] = ("MONDAY");
uint8_t string2[] = ("TUESDAY");

uint8_t let[] = {0,124,0,62,0,31,96,15,224,7,224,3,224,7,224,7,
	224,11,11,22,16,2,0,0,128,1,192,3,224,7,192,15,
	128,223,0,254,0,252,0,248,0,252,0,252,0,14,7,14,
	16,1,1,16,32,48,48,127,248,255,252,127,248,48,48,16,
	32,7,12,12,8,0,0,16,56,124,254,56,56,56,56,254,
	124,56,16,15,5,10,16,0,0,255,248,0,8,0,42,0,
	28,0,8,15,5,10,16,0,4,0,8,0,28,0,42,0,
	8,255,248,15,5,10,16,1,0,63,254,32,0,168,0,112,
	0,32,0,15,5,10,16,1,4,32,0,112,0,168,0,32,
	0,63,254,10,10,20,16,3,255,255,192,255,192,255,192,255,
	192,255,192,128,64,128,64,128,64,128,64,255,192,10,10,20,
	16,3,255,255,192,128,64,128,64,128,64,128,64,255,192,255};

uint8_t main(void){
    i2c_init();
	sh1106_init();
	sh1106_cls();

	sh1106_print(3, 0, string, str_length(string));
	sh1106_print(10, 1, string2, str_length(string2));
	
	sh1106_transmit(3, 3, let, str_length(let));
	
	return 0;
}

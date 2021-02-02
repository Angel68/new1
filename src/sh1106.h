#ifndef SH1106_H_
#define SH1106_H_

	#include "i2c.h"

	// Basic definitions
	#define SH1106_ADDRESS          0x3C
	#define SH1106_I2C_WRITE        ((SH1106_ADDRESS << 1) + I2C_WRITE)
	#define SH1106_I2C_READ         ((SH1106_ADDRESS << 1) + I2C_READ)
	#define SH1106_COMMAND          (0x00 | 0 << 6)
	#define SH1106_DATA             (0x00 | 1 << 6)

	// Fundamental commands
	#define SET_CONTRAST            0x81   // [2]
	#define SET_SEGMENT_REMAP_0_0   0xA0
	#define SET_SEGMENT_REMAP_127_0 0xA1
	#define ENTIRE_DISPLAY_ON       0xA4
	#define ENTIRE_DISPLAY_OFF      0xA5
	#define SET_NORMAL_DISPLAY      0xA6
	#define SET_INVERCED_DISPLAY    0xA7
	#define SET_DISPLAY_OFF         0xAE
	#define SET_DISPLAY_ON          0xAF

	// Scrolling commands
	#define RIGHT_HORIZONTAL_SCROLL 0x26    // [7]
	#define LEFT_HORIZONTAL_SCROLL  0x27    // [7]
	#define VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL    0x29    // [6]
	#define VERTICAL_AND_LEFT_HORIZONTAL_SCROLL     0x2A    // [6]
	#define STOP_SCROLL             0x2E    // After sending 0x2E RAM data needs to be rewritten
	#define START_SCROLL            0x2F
	#define SET_VERTICAL_SCROLL_AREA 0xA3   // [3]

	// Addressing setting commands
	#define SET_MEMORY_ADDRESSING_MODE 0x20     // [2]
	#define HORIZONTAL_ADDRESSING_MODE 0x00
	#define VERTICAL_ADDRESSING_MODE   0x01
	#define PAGE_ADDRESSING_MODE       0x02
	#define SET_COLUMN_ADDRESS         0x21     // [3] Only for horizontal or vertical addressing mode
	#define SET_PAGE_ADDRESS           0x22     // [3] Only for horizontal or vertical addressing mode

	// Hardware configuration
	#define SET_START_LINE          0x40
	#define SET_CHARGE_PUMP         0x8D    //  [2]
	#define SET_SEGMENT_REMAP       0xA0
	#define SET_MULTIPLEX_RATIO     0xA8    //  [2]
	#define SET_SCAN_DIRECTION      0xC0
	#define SET_COM_SCAN_DIRECTION  0xC8
	#define SET_DISPLAY_OFFSET      0xD3    //  [2]
	#define SET_PINS_CONFIGURATION  0xDA    //  [2]

	// Timing and driving scheme setting commands
	#define SET_CLOCK_FREQUENCY     0xD5    // [2]
	#define SET_PRECHARGE_PERIOD    0xD9    // [2]
	#define SET_VCOM_LEVEL          0xDB    // [2]
	#define DISPLAY_NOP             0xE3    // No operation command

	void sh1106_init(void);
	void sh1106_cls(void);
	void sh1106_test(void);
	void sh1106_transmit(uint8_t x, uint8_t y, uint8_t *data, uint8_t length);
	void sh1106_print(uint8_t x, uint8_t y, uint8_t *string, uint8_t length);

#endif	/* SH1106_H */

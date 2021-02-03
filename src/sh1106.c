/*
 * sh1106.c
 *
 * Created: 1/9/2020 3:42:43 PM
 *  Author: Angel68
 */ 

#include "sh1106.h"
#include "include/avr/pgmspace.h"

const char bukvy[] PROGMEM = { 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Space (dec32)
	0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x00, // !
	0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, // "
	0x00, 0x24, 0x7e, 0x24, 0x7e, 0x24, 0x00, 0x00, // #
	0x00, 0x4c, 0x92, 0xff, 0x92, 0x64, 0x00, 0x00, // $
	0x27, 0x15, 0x0b, 0x34, 0x2a, 0x39, 0x00, 0x00, // %
	0x00, 0x22, 0x55, 0x49, 0x32, 0x30, 0x48, 0x00, // &
	0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, // '
	0x00, 0x1c, 0x22, 0x41, 0x00, 0x00, 0x00, 0x00, // ( (dec40)
	0x00, 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, 0x00, // )
	0x49, 0x2a, 0x08, 0x7f, 0x08, 0x2a, 0x49, 0x00, // *
	0x00, 0x08, 0x08, 0x3e, 0x08, 0x08, 0x00, 0x00, // +
	0x00, 0x00, 0x00, 0x60, 0xe0, 0x00, 0x00, 0x00, // ,
	0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, // -
	0x00, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0x00, // .
	0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, // /
	0x00, 0x3e, 0x41, 0x49, 0x41, 0x3e, 0x00, 0x00, // 0
	0x00, 0x04, 0x02, 0x7f, 0x00, 0x00, 0x00, 0x00, // 1
	0x00, 0x42, 0x61, 0x51, 0x49, 0x46, 0x00, 0x00, // 2 (dec50)
	0x00, 0x22, 0x41, 0x49, 0x49, 0x36, 0x00, 0x00, // 3
	0x00, 0x18, 0x14, 0x12, 0x7f, 0x10, 0x00, 0x00, // 4
	0x00, 0x27, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00, // 5
	0x00, 0x3e, 0x49, 0x49, 0x49, 0x32, 0x00, 0x00, // 6
	0x00, 0x03, 0x01, 0x71, 0x09, 0x07, 0x00, 0x00, // 7
	0x00, 0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00, // 8
	0x00, 0x06, 0x49, 0x49, 0x49, 0x3e, 0x00, 0x00, // 9
	0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, // :
	0x00, 0x00, 0x66, 0xe6, 0x00, 0x00, 0x00, 0x00, // ;
	0x00, 0x00, 0x08, 0x14, 0x22, 0x00, 0x00, 0x00, // < (dec60)
	0x00, 0x00, 0x14, 0x14, 0x14, 0x14, 0x00, 0x00, // =
	0x00, 0x22, 0x14, 0x08, 0x00, 0x00, 0x00, 0x00, // >
	0x00, 0x02, 0x01, 0x51, 0x09, 0x06, 0x00, 0x00, // ?
	0x1c, 0x22, 0x49, 0x55, 0x5e, 0x20, 0x00, 0x00, // @
	0x00, 0x7C, 0x12, 0x12, 0x7C, 0x00, 0x00, 0x00, // A
	0x00, 0x7E, 0x4A, 0x4A, 0x34, 0x00, 0x00, 0x00, // B
	0x00, 0x3c, 0x42, 0x42, 0x24, 0x00, 0x00, 0x00, // C
	0x00, 0x7e, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, // D
	0x00, 0x7e, 0x4a, 0x4a, 0x42, 0x00, 0x00, 0x00, // E
	0x00, 0x7e, 0x0a, 0x0a, 0x02, 0x00, 0x00, 0x00, // F (dec70)
	0x00, 0x3c, 0x42, 0x62, 0x64, 0x00, 0x00, 0x00, // G
	0x00, 0x7e, 0x08, 0x08, 0x7e, 0x00, 0x00, 0x00, // H
	0x00, 0x00, 0x42, 0x7e, 0x42, 0x00, 0x00, 0x00, // I
	0x00, 0x22, 0x42, 0x3e, 0x02, 0x00, 0x00, 0x00, // J
	0x00, 0x7e, 0x18, 0x24, 0x42, 0x00, 0x00, 0x00, // K
	0x00, 0x7e, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, // L
	0x00, 0x7e, 0x04, 0x18, 0x04, 0x7e, 0x00, 0x00, // M
	0x00, 0x7e, 0x08, 0x10, 0x7e, 0x00, 0x00, 0x00, // N
	0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, // O
	0x00, 0x7e, 0x12, 0x12, 0x0c, 0x00, 0x00, 0x00, // P (dec80)
	0x00, 0x3c, 0x42, 0x62, 0x7c, 0x80, 0x00, 0x00, // Q
	0x00, 0x7e, 0x12, 0x32, 0x4c, 0x00, 0x00, 0x00, // R
	0x00, 0x24, 0x4a, 0x52, 0x24, 0x00, 0x00, 0x00, // S
	0x00, 0x02, 0x02, 0x7e, 0x02, 0x02, 0x00, 0x00, // T
	0x00, 0x3e, 0x40, 0x40, 0x40, 0x3e, 0x00, 0x00, // U
	0x00, 0x1e, 0x20, 0x40, 0x20, 0x1e, 0x00, 0x00, // V
	0x00, 0x3e, 0x40, 0x30, 0x40, 0x3e, 0x00, 0x00, // W
	0x00, 0x42, 0x24, 0x18, 0x24, 0x42, 0x00, 0x00, // X
	0x00, 0x06, 0x08, 0x70, 0x08, 0x06, 0x00, 0x00, // Y
	0x00, 0x62, 0x52, 0x4a, 0x46, 0x00, 0x00, 0x00, // Z (dec90)
	0x00, 0x7e, 0x42, 0x42, 0x00, 0x00, 0x00, 0x00, // [
	0x00, 0x00, 0x06, 0x18, 0x60, 0x00, 0x00, 0x00, // backslash
	0x00, 0x00, 0x42, 0x42, 0x7e, 0x00, 0x00, 0x00, // ]
	0x00, 0x04, 0x02, 0x01, 0x02, 0x04, 0x00, 0x00, // ^
	0x00, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, // _
	0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, // `
	0x00, 0x30, 0x4a, 0x4a, 0x3c, 0x40, 0x00, 0x00, // a
	0x00, 0x7e, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00, // b
	0x00, 0x38, 0x44, 0x44, 0x28, 0x00, 0x00, 0x00, // c
	0x00, 0x30, 0x48, 0x48, 0x7e, 0x00, 0x00, 0x00, // d (dec100)
	0x00, 0x38, 0x54, 0x54, 0x18, 0x00, 0x00, 0x00, // e
	0x00, 0x10, 0x7c, 0x12, 0x04, 0x00, 0x00, 0x00, // f
	0x00, 0x18, 0xa4, 0xa4, 0x5a, 0x00, 0x00, 0x00, // g
	0x00, 0x7e, 0x08, 0x08, 0x70, 0x00, 0x00, 0x00, // h
	0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x00, 0x00, // i
	0x00, 0x00, 0x40, 0x80, 0x7a, 0x00, 0x00, 0x00, // j
	0x00, 0x7e, 0x30, 0x48, 0x00, 0x00, 0x00, 0x00, // k
	0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, // l
	0x00, 0x78, 0x08, 0x70, 0x08, 0x70, 0x00, 0x00, // m
	0x00, 0x78, 0x08, 0x08, 0x70, 0x00, 0x00, 0x00, // n (dec110)
	0x00, 0x30, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00, // o
	0x00, 0xf8, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, // p
	0x00, 0x18, 0x24, 0x24, 0xf8, 0x00, 0x00, 0x00, // q
	0x00, 0x7c, 0x08, 0x04, 0x08, 0x00, 0x00, 0x00, // r
	0x00, 0x48, 0x54, 0x24, 0x00, 0x00, 0x00, 0x00, // s
	0x00, 0x08, 0x3e, 0x48, 0x20, 0x00, 0x00, 0x00, // t
	0x00, 0x38, 0x40, 0x40, 0x78, 0x00, 0x00, 0x00, // u
	0x00, 0x38, 0x40, 0x20, 0x18, 0x00, 0x00, 0x00, // v
	0x00, 0x38, 0x40, 0x38, 0x40, 0x38, 0x00, 0x00, // w
	0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00, // x (dec120)
	0x00, 0x18, 0xa0, 0xa0, 0x58, 0x00, 0x00, 0x00, // y
	0x00, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x00, 0x00, // z
	0x00, 0x00, 0x10, 0x6c, 0x82, 0x00, 0x00, 0x00, // {
	0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, // |
	0x00, 0x00, 0x82, 0x6c, 0x10, 0x00, 0x00, 0x00, // }
	0x10, 0x08, 0x08, 0x10, 0x10, 0x08, 0x00, 0x00, // ~
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00, // [del] (dec127)
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00, // (dec130)
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00, // (dec140)
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00, // (dec150)
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x7d, 0x54, 0x54, 0x45, 0x00, 0x00, 0x00, // ? (dec160)
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00, // (dec170)
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00, 0x00,
	0x00, 0x7c, 0x12, 0x12, 0x7c, 0x00, 0x00, 0x00, // ? ?
	0x00, 0x7e, 0x4a, 0x4a, 0x32, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x4a, 0x4a, 0x34, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, // ?
	0x60, 0x3c, 0x22, 0x22, 0x3c, 0x60, 0x00, 0x00, // ? (dec180) ?
	0x00, 0x7e, 0x4a, 0x4a, 0x42, 0x00, 0x00, 0x00, // ?
	0x00, 0x76, 0x08, 0x7e, 0x08, 0x76, 0x00, 0x00, // ?
	0x00, 0x24, 0x42, 0x4a, 0x34, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x10, 0x08, 0x7e, 0x00, 0x00, 0x00, // ?
	0x00, 0x7c, 0x21, 0x11, 0x7c, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x18, 0x24, 0x42, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x04, 0x02, 0x7e, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x04, 0x08, 0x04, 0x7e, 0x00, 0x00, // ?
	0x00, 0x7e, 0x10, 0x10, 0x7e, 0x00, 0x00, 0x00, // ?
	0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00, 0x00, 0x00, // ? (dec190)?
	0x00, 0x7e, 0x02, 0x02, 0x7e, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x12, 0x12, 0x0c, 0x00, 0x00, 0x00, // ?
	0x00, 0x3c, 0x42, 0x42, 0x24, 0x00, 0x00, 0x00, // ?
	0x00, 0x02, 0x02, 0x7e, 0x02, 0x02, 0x00, 0x00, // ?
	0x00, 0x06, 0x48, 0x48, 0x36, 0x00, 0x00, 0x00, // ?
	0x00, 0x0c, 0x12, 0x7e, 0x12, 0x0c, 0x00, 0x00, // ?
	0x00, 0x22, 0x14, 0x08, 0x14, 0x22, 0x00, 0x00, // ?
	0x00, 0x3e, 0x20, 0x20, 0x3e, 0x60, 0x00, 0x00, // ?
	0x00, 0x0e, 0x10, 0x10, 0x7e, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x40, 0x7c, 0x40, 0x7e, 0x00, 0x00, // ? (dec200) ?
	0x00, 0x7e, 0x40, 0x7c, 0x40, 0x7e, 0xc0, 0x00, // ?
	0x00, 0x02, 0x7e, 0x48, 0x48, 0x30, 0x00, 0x00, // ?
	0x00, 0x7e, 0x48, 0x30, 0x00, 0x7e, 0x00, 0x00, // ?
	0x00, 0x00, 0x7e, 0x48, 0x48, 0x30, 0x00, 0x00, // ?
	0x00, 0x24, 0x42, 0x4a, 0x3c, 0x00, 0x00, 0x00, // ?
	0x00, 0x7e, 0x08, 0x3c, 0x42, 0x3c, 0x00, 0x00, // ?
	0x00, 0x4c, 0x32, 0x12, 0x7e, 0x00, 0x00, 0x00, // ?
	0x00, 0x30, 0x48, 0x48, 0x38, 0x40, 0x00, 0x00, // ?
	0x00, 0x30, 0x4b, 0x4d, 0x39, 0x00, 0x00, 0x00, // ?
	0x00, 0x38, 0x54, 0x28, 0x00, 0x00, 0x00, 0x00, // ?  (dec210) ?
	0x00, 0x78, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, // ?
	0x00, 0x30, 0x4a, 0x4c, 0x38, 0x00, 0x00, 0x00, // ?
	0x00, 0x38, 0x54, 0x54, 0x58, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x20, 0x78, 0x20, 0x78, 0x00, 0x00, // ?
	0x00, 0x00, 0x44, 0x54, 0x28, 0x00, 0x00, 0x00, // ?
	0x00, 0x38, 0x40, 0x40, 0x78, 0x00, 0x00, 0x00, // ?
	0x00, 0x38, 0x42, 0x42, 0x78, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x10, 0x68, 0x00, 0x00, 0x00, 0x00, // ?
	0x00, 0x70, 0x08, 0x78, 0x00, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x10, 0x20, 0x10, 0x78, 0x00, 0x00, // ?  (dec220) ?
	0x00, 0x78, 0x10, 0x78, 0x00, 0x00, 0x00, 0x00, // ?
	0x00, 0x30, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x08, 0x08, 0x70, 0x00, 0x00, 0x00, // ?
	0x00, 0xf8, 0x28, 0x28, 0x10, 0x00, 0x00, 0x00, // ?
	0x00, 0x30, 0x48, 0x48, 0x00, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x08, 0x78, 0x08, 0x70, 0x00, 0x00, // ?
	0x00, 0x08, 0x50, 0x20, 0x18, 0x00, 0x00, 0x00, // ?
	0x00, 0x10, 0x28, 0xf8, 0x28, 0x10, 0x00, 0x00, // ?
	0x00, 0x48, 0x30, 0x30, 0x48, 0x00, 0x00, 0x00, // ?
	0x00, 0x3c, 0x20, 0x20, 0x3c, 0x60, 0x00, 0x00, // ?  (dec230) ?
	0x00, 0x18, 0x20, 0x20, 0x78, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x40, 0x70, 0x40, 0x78, 0x00, 0x00, // ?
	0x00, 0x78, 0x40, 0x70, 0x40, 0x78, 0xc0, 0x00, // ?
	0x00, 0x08, 0x78, 0x50, 0x20, 0x00, 0x00, 0x00, // ?
	0x00, 0x78, 0x50, 0x20, 0x00, 0x78, 0x00, 0x00, // ?
	0x00, 0x00, 0x78, 0x50, 0x20, 0x00, 0x00, 0x00, // ?
	0x00, 0x00, 0x44, 0x54, 0x38, 0x00, 0x00, 0x00, // ?
	0x00, 0x7c, 0x10, 0x38, 0x44, 0x38, 0x00, 0x00, // ?
	0x00, 0x00, 0x00, 0x48, 0x34, 0x7c, 0x00, 0x00, // ?
	0x00, 0x7e, 0x04, 0x08, 0x7e, 0x24, 0x2a, 0x24, // ?  (dec240) ?
	0x00, 0x38, 0x55, 0x54, 0x19, 0x00, 0x00, 0x00  // ?
};

const char big_numbers[] PROGMEM = {
	0x00, 0x00, 0x00, 0xf8, 0x04, 0x02, 0x02, 0x02, // Zero
	0x02, 0x02, 0x02, 0x04, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x1f, 0x20, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x20, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x10, 0x08, // One
	0x04, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x02, 0x02, // Two
	0x02, 0x02, 0x02, 0x84, 0x78, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x50, 0x48,
	0x44, 0x42, 0x41, 0x40, 0x40, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x02, 0x02, // Three
	0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x21, 0x1e, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, // Four
	0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x7f, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x7e, 0x42, 0x42, 0x42, // Five
	0x42, 0x42, 0x42, 0x82, 0x02, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x20, 0x1f, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xf8, 0x04, 0x82, 0x82, 0x82, // Six
	0x82, 0x82, 0x82, 0x04, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x1f, 0x21, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x21, 0x1e, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, // Seven
	0x02, 0x82, 0x42, 0x22, 0x1e, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82, // Eight
	0x82, 0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x1e, 0x21, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x21, 0x1e, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x78, 0x84, 0x02, 0x02, 0x02, // Nine
	0x02, 0x02, 0x02, 0x84, 0xf8, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x41, 0x41, 0x41,
	0x41, 0x41, 0x41, 0x20, 0x1f, 0x00, 0x00, 0x00
};

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
	i2c_write(0x00); // Minimum brightness
	//i2c_write(0xff);	
	i2c_write(SET_PRECHARGE_PERIOD);
	i2c_write(0xF1);
	i2c_write(SET_VCOM_LEVEL);
	i2c_write(0x40);
	i2c_write(STOP_SCROLL);
	i2c_write(DISPLAY_POWER_ON);
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

/*
void sh1106_transmit(uint8_t x, uint8_t y, uint8_t data){
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
	
	i2c_write(data);
	i2c_stop();
};

void sh1106_print(uint8_t x, uint8_t y, char* str, uint8_t length){
	for (uint8_t ii = 0; ii < (length); ii++){
		pBukvy = &bukvy[((*str)-0x20)*8];
		for (uint8_t i = 0; i < 6; i++){
			sh1106_transmit(x++, y, *pBukvy++);
		}
		str++;
	}
};*/

/*
void sh1106_print(uint8_t x, uint8_t y, char* str, uint8_t length){
	uint8_t *pBukvy;
	
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
	
	for(uint8_t ii = 0; ii < (length); ii++){		pBukvy = &bukvy[((*str)-0x20)*8];		for (uint8_t i = 0; i < 6; i++){			i2c_write(*pBukvy++);		}		str++;	}
	i2c_stop();
};*/

void sh1106_print(uint8_t x, uint8_t y, char* str, uint8_t length){
	//char *p;
	
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
	
	uint16_t index = 0;
	for(uint8_t i = 0; i < (length); i++){
		index = ((*str)-0x20)*8; // 0x20 - delta of array of letters and ASCII table start index
		for (uint8_t ii = 0; ii < 6; ii++){
			i2c_write(pgm_read_byte(&(bukvy[index])));
			index++;
		}
		str++;
	}
	i2c_stop();
};

void sh1106_print_big_number(uint8_t x, uint8_t y, char* str){
	uint8_t number_width = 13;
	
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_COMMAND);
	
	i2c_write(SET_MEMORY_ADDRESSING_MODE);
	i2c_write(PAGE_ADDRESSING_MODE);
	
	i2c_write(0x00|(x&0x0F)); // Set start column lower nimble  [0x00~0x0F]
	i2c_write(0x10|(x>>4));   // Set start column higher nimble [0x10~0x1F]
	
	(y >= 0 && y <= 6) ? i2c_write(0xB0|y) : i2c_write(0xB0); // Set page number [0xB0~0xB6]
	
	i2c_stop();
	
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_DATA);
	
	uint16_t index = 0;
	index = (((*str)-0x30)*32);
		for (uint8_t ii = 0; ii < number_width; ii++){
			i2c_write(pgm_read_byte(&(big_numbers[index])));
			index++;
		}
		
	str++;
	index = (((*str)-0x30)*32);
	for (uint8_t ii = 0; ii < number_width; ii++){
		i2c_write(pgm_read_byte(&(big_numbers[index])));
		index++;
	}
	i2c_stop();
	
	////////////////////////////////////Second row///////////////////////////////////
	str--;
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_COMMAND);
	
	i2c_write(SET_MEMORY_ADDRESSING_MODE);
	i2c_write(PAGE_ADDRESSING_MODE);
	
	i2c_write(0x00|(x&0x0F)); // Set start column lower nimble  [0x00~0x0F]
	i2c_write(0x10|(x>>4));   // Set start column higher nimble [0x10~0x1F]
	
	(y >= 0 && y <= 6) ? i2c_write(0xB0|(y+1)) : i2c_write(0xB0+1); // Set page number [0xB1~0xB7]
	
	i2c_stop();	
	i2c_start(SH1106_I2C_WRITE);
	i2c_write(SH1106_DATA);	
	index = ((((*str)-0x30)*32)+16);
	for (uint8_t ii = 0; ii < number_width; ii++){
		i2c_write(pgm_read_byte(&(big_numbers[index])));
		index++;
	}
	
	str++;
	index = ((((*str)-0x30)*32)+16);
	for (uint8_t ii = 0; ii < number_width; ii++){
		i2c_write(pgm_read_byte(&(big_numbers[index])));
		index++;
	}
	i2c_stop();
};
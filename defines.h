#define PIN_CLOCK_INPUT 1
#define PIN_RESET_INPUT 0

#define PIN_CLOCK_BUTTON 2
#define PIN_RESET_BUTTON 3

#define PIN_SWITCH_A 5
#define PIN_SWITCH_B 6

#define DISPLAY_I2C_ADDRESS 0x03
#define EEPROM_I2C_ADDRESS 0x50  // 80 decimal
#define DAC_I2C_ADDRESS 0x60     // 90 decimal

#define TOP_DISPLAY 0
#define BOTTOM_DISPLAY 1

#define SEQUENCE_PLAYBACK_MODE 0
#define SEQUENCE_EDIT_MODE 1
#define SETTINGS_MODE 2

#define RST_ASSIGNMENT_RESET 0
#define RST_ASSIGNMENT_SAMPLE_AND_HOLD 1

#define MAX_SEQUENCE_LENGTH 64 // max 256 to fit into 1 byte

#define MEM_ADDR_SEQUENCE_LENGTH 130
#define MEM_ADDR_CLOCK_DIVISION 132
#define MEM_ADDR_QUANTIZATION 134
#define MEM_ADDR_SELF_INITIALIZATION 136
#define MEM_ADDR_SCALE 138
#define MEM_ADDR_INTENSITY 140
#define MEM_ADDR_SLIP 142
#define MEM_ADDR_DRIFT_PERCENTAGE 144
#define MEM_ADDR_DRIFT_AMOUNT 146
#define MEM_ADDR_HOLD 148
#define MEM_ADDR_SONG 150
#define MEM_ADDR_SONG2 152
#define MEM_ADDR_HOLD_OFFSET 154
#define MEM_ADDR_HOLD_THRESHOLD 156
#define MEM_RST_INPUT_ASSIGNMENT 158

#define NUMBER_OF_SETTINGS_PAGES 16
#define NUMBER_OF_SCALES 14
#define NUMBER_OF_SONGS 16

// 7-segment LED font

#define __a__ 0b01110111
#define __A__ 0b01110111
#define __d__ 0b00111101
#define __c__ 0b00001101
#define __C__ 0b01001110
#define __E__ 0b01001111
#define __g__ 0b01111011
#define __h__ 0b00010111
#define __H__ 0b00110111
#define __i__ 0b00010000
#define __I__ 0b00010000
#define __j__ 0b00111000
#define __L__ 0b00001110
#define __M__ 0b01010100
#define __m__ 0b01010100
#define __n__ 0b00010101
#define __o__ 0b00011101
#define __O__ 0b01111110
#define __P__ 0b01100111
#define __r__ 0b00000101
#define __S__ 0b01011011
#define __t__ 0b00001111
#define __v__ 0b00011100
#define __Y__ 0b00100111
#define __space__ 0b00000000

#define __dash__ 0b00000001
#define __underscore__ 0b00001000




#ifndef DualDisplayDriver_h
#define DualDisplayDriver_h

#define DISPLAY_A 0
#define DISPLAY_B 1

#include "Arduino.h"
#include <Wire.h>
#include "defines.h"
#include "Snapshot.h"

class DualDisplayDriver
{
  public:
    DualDisplayDriver(uint8_t i2c_address, Snapshot *snapshot);
    void init();
    void write(uint8_t display, uint16_t value);
    void writeSetting(uint8_t display, uint16_t value, byte byte_code);
    void writeDigit(byte digit, byte value);
    void writeByteCode(byte digit, byte byte_code);
    void setIntensity(uint8_t intensity); // 0-16

    uint8_t i2c_address;
    uint8_t intensity = 15;

    Snapshot *snapshot;

    // The digits array is used to prevent redundant updates
    // of the bubble display digits.
    byte digits[8];

    byte byte_codes[10] = {
    	0b01111110, // 0
    	0b00110000, // 1
    	0b01101101, // 2
    	0b01111001, // 3
    	0b00110011, // 4
    	0b01011011, // 5
    	0b01011111, // 6
    	0b01110000, // 7
    	0b01111111, // 8
    	0b01111011  // 9
    };

    // 0b01110111, // A
    // 0b01001110, // C
    // 0b00001101, // c 
    // 0b00111101, // d         
    // 0b00101111, // H
    // 0b00010111, // h
    // 0b00010000, // i    
    // 0b01001111, // E
    // 0b00001110, // L
    // 0b00011101, // o
    // 0b01100111, // P

    // 0b00000101, // r
    // 0b01011011, // S
    // 0b00010101, // n
    // 0b01111011, // g 
    // 0b00111110, // V
    // 0b00011100, // v

};

#endif
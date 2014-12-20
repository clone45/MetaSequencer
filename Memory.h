#ifndef Memory_h
#define Memory_h

#include "Arduino.h"
#include <Wire.h>

class Memory
{
  public:
    Memory(uint8_t i2c_address);

    void init();
	uint8_t read(uint16_t memory_address);
	void write(uint16_t memory_address, uint8_t value);

    uint8_t i2c_address;
};

#endif
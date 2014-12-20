#include "Arduino.h"
#include "Memory.h"

Memory::Memory(uint8_t i2c_address)
{
  this->i2c_address = i2c_address;
}

void Memory::init()
{
}

uint8_t Memory::read(uint16_t memory_address)
{
  
  uint8_t results = 0;

  // Send the memory address
  Wire.beginTransmission(this->i2c_address);
  Wire.write(highByte(memory_address));
  Wire.write(lowByte(memory_address));
  Wire.endTransmission();

  // Request 1 byte
  Wire.requestFrom(this->i2c_address, (uint8_t) 1);

  // Read from the memory address
  if(Wire.available()) results = Wire.read();

  return(results);
}

void Memory::write(uint16_t memory_address, uint8_t value)
{
  Wire.beginTransmission(this->i2c_address);

  // Send the memory address
  Wire.write(highByte(memory_address));
  Wire.write(lowByte(memory_address));

  // Send the value to write
  Wire.write(value);

  Wire.endTransmission(); 

  // This delay is very important.  The memory needs some
  // time to complete the write cycle.
  delay(8);
}
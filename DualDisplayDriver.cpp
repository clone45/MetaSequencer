#include "Arduino.h"
#include "DualDisplayDriver.h"

DualDisplayDriver::DualDisplayDriver(uint8_t i2c_address, Snapshot *snapshot)
{
  this->i2c_address = i2c_address;
  this->snapshot = snapshot;
}

void DualDisplayDriver::init()
{

  for(uint8_t digit=0; digit<8; digit++)
  {
    digits[digit] = 0;
  }

  // Reset chip (Why?  I have no idea.)
  Wire.beginTransmission(0x00);
  Wire.write(0x0C);
  Wire.write(0x01 | 0x01);
  Wire.endTransmission();  

  // Set display driver I2C address
  Wire.beginTransmission(0x00);    // Default I2C address
  Wire.write(0x2D);                // Command to set self addressing register
  Wire.write(i2c_address);         // Value of new I2C address
  Wire.endTransmission();
  
  delay(20);

  // Decode modes and hex codes
  //
  // 0x00 = No decode for digits 7:0
  // 0x01 = Code-B/HEX decode for digit 0. No decodee for digits 7:1
  // 0x07 = Code-B/HEX decode for digit 0:2. No decodee for digits 7:3
  // 0x3F = Code-B/HEX decode for digit 0:5. No decodee for digits 7:6
  // 0x25 = Code-B/HEX decode for digit 0,2,5. No decodee for digits 1,3,4,6,7
  //
  // Set decode mode
  Wire.beginTransmission(i2c_address);
  Wire.write(0x09);  // Command to set decode mode
  Wire.write(0x00);  // No decode for digits 7:0
  Wire.endTransmission();

  // Set global intensity
  Wire.beginTransmission(i2c_address);
  Wire.write(0x0A);  // Command to set intensity control register (globally)
  Wire.write(this->snapshot->display_intensity);  // Intensity: range: 0x00, 0x01, 0x02... 0x0F
  Wire.endTransmission();
  
  // Set scan limit (which digits should be displayed)
  Wire.beginTransmission(i2c_address);
  Wire.write(0x0B);  // Command to set scan limit
  Wire.write(0x07);  // Display digits 0:7
  Wire.endTransmission();
  
  // Shutdown modes and hex codes:
  //
  // 0x00 = Shutdown Mode, Reset Feature Register to Default Settings
  // 0x80 = Shutdown Mode, Feature Register Unchanged
  // 0x01 = Normal Operation, Reset Feature Register To Default Settings
  // 0x81 = Normal Operation, Feature Register Unchanged
  //
  // Set shutdown mode
  Wire.beginTransmission(i2c_address);
  Wire.write(0x0C);  // Command to set Shutdown Register
  Wire.write(0x01);  // Set to normal operation, reset feature register
  Wire.endTransmission();

}

void DualDisplayDriver::setIntensity(uint8_t intensity) // 0 - 16
{
  if(this->snapshot->display_intensity != intensity)
  {
    this->intensity = intensity;

    this->snapshot->setDisplayIntensity(intensity);

    Wire.beginTransmission(i2c_address);
    Wire.write(0x0A);  // Command to set intensity control register (globally)
    Wire.write(intensity);  // Intensity: range: 0x00, 0x01, 0x02... 0x0F
    Wire.endTransmission();
  }
}

void DualDisplayDriver::write(uint8_t display, uint16_t value)
{
  if(display == DISPLAY_A)
  {
    this->writeDigit(0, value / 1000);
    this->writeDigit(1, (value / 100) % 10);
    this->writeDigit(2, (value / 10) % 10);
    this->writeDigit(3, value % 10);
  }
  
  if(display == DISPLAY_B)
  {
    this->writeDigit(4, value / 1000);
    this->writeDigit(5, (value / 100) % 10);
    this->writeDigit(6, (value / 10) % 10);
    this->writeDigit(7, value % 10);
  } 
}

void DualDisplayDriver::writeSetting(uint8_t display, uint16_t value, byte byte_code)
{
  if(display == DISPLAY_A)
  {
    this->writeByteCode(0, byte_code);
    this->writeDigit(1, (value / 100) % 10);
    this->writeDigit(2, (value / 10) % 10);
    this->writeDigit(3, value % 10);
  }
  
  if(display == DISPLAY_B)
  {
    this->writeByteCode(4, byte_code);
    this->writeDigit(5, (value / 100) % 10);
    this->writeDigit(6, (value / 10) % 10);
    this->writeDigit(7, value % 10);
  } 
}

void DualDisplayDriver::writeDigit(byte digit, byte value)
{
  byte byte_code = this->byte_codes[value];
  this->writeByteCode(digit, byte_code);
}

void DualDisplayDriver::writeByteCode(byte digit, byte byte_code)
{
  if(digits[digit] != byte_code)
  {
    Wire.beginTransmission(i2c_address);
    Wire.write(digit + 1);
    Wire.write(byte_code);
    Wire.endTransmission();

    digits[digit] = byte_code;
  }
}
//
// Encoder code modified from: 
// http://hifiduino.wordpress.com/2010/10/20/rotaryencoder-hw-sw-no-debounce/
//

#include "Arduino.h"
#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pin_a, uint8_t pin_b, uint8_t pin_c)
{
  this->pin_a = pin_a;
  this->pin_b = pin_b;
  this->pin_c = pin_c;

  pinMode(this->pin_a, INPUT_PULLUP);
  pinMode(this->pin_b, INPUT_PULLUP);
  pinMode(this->pin_c, INPUT_PULLUP);

  if(digitalRead(this->pin_c) == 1) 
  {
    this->state |= 0b00000010;
  }

  if(digitalRead(this->pin_b) == 1) 
  {
    this->state |= 0b00000001;
  }  
}

void RotaryEncoder::init()
{
  // Read the encoder and throw away the first reading.  This is important,
  // otherwise the first reading of the rotary encoder might incorrectly
  // report a state change.
  this->read();
}

int8_t RotaryEncoder::read()
{
  state <<= 2;

  // add current state
  if(digitalRead(this->pin_c) == 1) 
  {
    state |= 0b00000010;
  }

  if(digitalRead(this->pin_b) == 1) 
  {
    state |= 0b00000001;
  }

  return (this->enc_states[( state & 0x0f )]);	// 0x0F == 0000 1111
}

int8_t RotaryEncoder::readButton()
{
  return (! digitalRead(this->pin_a));  
}

boolean RotaryEncoder::released()
{
  boolean button_value = ! digitalRead(this->pin_a);

  if(old_button_value == true && button_value == false)
  {
    old_button_value = button_value;
    return(true);
  }

  old_button_value = button_value;
  return(false);
}
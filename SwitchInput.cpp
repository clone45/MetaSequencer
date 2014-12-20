#include "Arduino.h"
#include "SwitchInput.h"

SwitchInput::SwitchInput(uint8_t pin1, uint8_t pin2)
{
  this->pin1 = pin1;
  this->pin2 = pin2;
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
}

void SwitchInput::poll()
{
  uint8_t p1 = ! digitalRead(this->pin1);
  uint8_t p2 = ! digitalRead(this->pin2);

  if(p1)
  {
    position = 3;
  }
  else if(p2)
  {
    position = 1;
  }
  else
  {
    position = 2;
  }
}

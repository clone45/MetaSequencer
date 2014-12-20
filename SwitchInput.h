#ifndef SwitchInput_h
#define SwitchInput_h

#include "Arduino.h"

class SwitchInput
{
  public:

  	// Methods 
    SwitchInput(uint8_t pin1, uint8_t pin2);
    void poll();

    // Variables
  	uint8_t position = 0;
    uint8_t pin1;
    uint8_t pin2;
};

#endif
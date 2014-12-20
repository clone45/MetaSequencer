#ifndef TriggerInput_h
#define TriggerInput_h

#include "Arduino.h"

class TriggerInput
{
  public:

  	// Methods 
    TriggerInput(uint8_t pin);
    void poll();
    boolean read();
    void setDebounce(uint32_t debounce_delay);

    // Variables
  	boolean triggered = false;
  	boolean old_pin_value = false;
  	uint8_t pin;

  	uint32_t last_debounce_time = 0;
  	uint32_t debounce_delay = 50; // 50 milliseconds
};

#endif
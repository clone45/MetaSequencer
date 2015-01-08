#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Arduino.h"
#include <Wire.h>

class RotaryEncoder
{
  public:
    RotaryEncoder(uint8_t pin_a, uint8_t pin_b, uint8_t pin_c);
    void init();
    int8_t read();
	int8_t readButton();
    boolean released();
    boolean pressed();

    uint8_t state;
    uint8_t pin_a;
    uint8_t pin_b;
    uint8_t pin_c;

    boolean old_button_value = false;

    int8_t enc_states[16] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};

    // Debouncing for push-in switch
    uint32_t last_debounce_time = 0;
    uint32_t debounce_delay = 50; // 50 milliseconds
};

#endif
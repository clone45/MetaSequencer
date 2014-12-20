#include "Arduino.h"
#include "TriggerInput.h"

TriggerInput::TriggerInput(uint8_t pin)
{
  this->pin = pin;
  pinMode(pin, INPUT_PULLUP);
}

//
// void TriggerInput::poll()
//
// Reads the value of the trigger input and sets the class
// variable 'triggered' if the input was triggered on this
// pollilng cycle.  Uses code debouncing.
//

void TriggerInput::poll()
{
  if ((millis() - last_debounce_time) > debounce_delay) 
  {
    boolean pin_value = ! digitalRead(this->pin);

    if(pin_value && (old_pin_value == false))
    {
      this->triggered = true;
    }
    else
    {
      this->triggered = false;
    }

    if(old_pin_value != pin_value) last_debounce_time = millis();

    this->old_pin_value = pin_value;
  }
  else
  {
    this->triggered = false;
  }
}

//
// boolean TriggerInput::read()
//
// Reads the value of the trigger input and returns it.
//

boolean TriggerInput::read()
{
  return(! digitalRead(this->pin));
}

//
// boolean TriggerInput::setDebounce()
//
// Sets the debounce time, in milliseconds used in TriggerInput::poll()
//

void TriggerInput::setDebounce(uint32_t debounce_delay)
{
  this->debounce_delay = debounce_delay;
}

#ifndef Sequencer_h
#define Sequencer_h

#include "Arduino.h"
#include "defines.h"
#include <Wire.h>
#include "Memory.h"

class Sequencer
{
  public:

  	// Methods 
    Sequencer();
    
    void init();
    void resetDrift();

    // Variables
    int16_t drift[MAX_SEQUENCE_LENGTH];     // stores drift values
    
};

#endif
#ifndef Output_h
#define Output_h

#include "Arduino.h"
#include <Wire.h>
#include "defines.h"
#include "Snapshot.h"
#include "GlobalScales.h"
#include "Transposer.h"
          
class Output
{
  public:

  	// Methods 
    Output(uint8_t i2c_address, Snapshot *snapshot, Transposer *transposer, Transposer *transposer2);
    void write(uint16_t value);
    uint8_t getScale();
    uint16_t quantize(uint16_t value);

    // Variables
    uint8_t i2c_address;
    uint16_t old_value = 32768;

    Transposer *transposer;
    Transposer *transposer2;
    Snapshot *snapshot;
};

#endif
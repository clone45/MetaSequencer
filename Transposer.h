#ifndef Transposer_h
#define Transposer_h

#include "Arduino.h"
#include <Wire.h>
#include "defines.h"
#include "Snapshot.h"
#include "GlobalTranspositionTables.h"
          
class Transposer
{
  public:

  	// Methods 
    Transposer(Snapshot *snapshot);
    void clock();
    void step();
    void reset();
    uint16_t transpose(int16_t value, uint8_t song);

    // Variables
    uint16_t pattern_step = 0;
    uint16_t pattern_number = 0;
    uint8_t clock_division = 1;
    int8_t clock_counter = 0;

    Snapshot *snapshot;   
};

#endif
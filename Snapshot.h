#ifndef Snapshot_h
#define Snapshot_h

#include "Arduino.h"
#include "defines.h"
#include <Wire.h>
#include "Memory.h"

class Snapshot
{
    public:

        // Methods 
        Snapshot(Memory *memory);

        void init();

        void setValue(uint16_t step, uint16_t value);
        void setStep(uint16_t step);
        void setSequenceLength(uint16_t length);
        void setClockDivision(uint16_t clock_division);
        void setSlip(uint8_t length);
        void setDriftPercentage(uint8_t length);
        void setDriftAmount(uint16_t length);
        void setDisplayIntensity(uint8_t intensity);
        void setScale(uint8_t scale);
        void setSong(uint16_t song);
        void setSong2(uint16_t song);
        void setHold(uint8_t hold);
        void setHoldOffset(uint16_t hold_offset);
        void setHoldThreshold(uint16_t hold_threshold);
        void setRstInputAssignment(uint8_t rst_input_assignment);
        void setPressFunctionality(uint8_t press_functionality);

        // Variables
        uint16_t sequence[MAX_SEQUENCE_LENGTH]; // stores sequencer values

        uint16_t step = 0;
        uint16_t sequence_length = 8;   // Sequence length
        uint16_t clock_division = 1;    // clock division
        uint8_t slip = 0;               // Percentage chance to slip
        uint8_t drift_percentage = 0;   // Percentage changce to drift
        uint16_t drift_amount = 0;      // Amount to drift
        uint8_t hold = 0;
        uint16_t hold_offset = 0;
        uint16_t hold_threshold = 0;
        uint8_t display_intensity = 15; // Display brightness
        uint8_t scale = 0;              // Quantization musical scale
        uint16_t song = 0;
        uint16_t song2 = 0;
        uint8_t rst_input_assignment = 0;
        uint8_t press_functionality = 0;

    private:

        Memory *memory;
};

/*

Snapshot memory consumption
===========================

16 * (64 + 5) = 1104 bits = 138 bytes = 69 uint16_t.  Which should allow for 4 snapshots

*/

#endif
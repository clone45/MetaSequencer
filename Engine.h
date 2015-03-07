#ifndef Engine_h
#define Engine_h

#include <Wire.h>

#include "Arduino.h"
#include "defines.h"
#include "DualDisplayDriver.h"
#include "RotaryEncoder.h"
#include "Memory.h"
#include "Snapshot.h"
#include "Sequencer.h"
#include "TriggerInput.h"
#include "SwitchInput.h"
#include "Transposer.h"
#include "Output.h"
#include "Rand.h"

class Engine
{
  public:
    Engine();
    void init();
    void loop();
    void factoryReset();

    void sequencePlaybackMode();
    void sequenceEditMode();
    void settingsMode();

    void playback();

    // Global variables of the sequencer
    uint8_t step = 0;
    int16_t value = 0;
    int32_t output_value = 0;    
    uint16_t old_value = 0;

    int16_t realtime_recording_value = 0;

    int16_t z_sequence_length = 0;
    int16_t z_clock_division = 0;
    int8_t z_scale = 0;
    int8_t z_edit_step = 0;
    int8_t z_intensity = 0;
    int16_t z_hold = 0;
    int16_t z_hold_offset = 0;
    int16_t hold_threshold = 0;
    int8_t z_song = 0;
    int8_t z_song2 = 0;

    int16_t drift = 0;
    uint16_t clock_counter = 0;

    int8_t edit_step = 0;
    int16_t edit_value = 0;

    boolean sample = false;

    // Always start in playback mode
    uint8_t mode = SEQUENCE_PLAYBACK_MODE;
    uint8_t rst_input_assignment = RST_ASSIGNMENT_RESET;
    int8_t settings_page = 0;
    int8_t z_settings_page = 0;

    // Random number generator
    Rand *rnd;

    // Sequencer object
    Sequencer *sequencer;

    // Snapshot object
    Snapshot *snapshot;
    // Snapshot *snapshots[NUMBER_OF_SNAPSHOTS];

    Transposer *transposer;
    Transposer *transposer2;

    // Memory, and display objects (I2C devices)
    Memory *memory;
    DualDisplayDriver *dual_display_driver;

    // Rotary encoder objects
    RotaryEncoder *step_encoder;  // top encoder
    RotaryEncoder *value_encoder;   // bottom encoder

    // Trigger input objects
    TriggerInput *clock_button;
    TriggerInput *clock_input;
    TriggerInput *reset_button;
    TriggerInput *reset_input;

    // Mode switch
    SwitchInput *mode_switch;

    // Output object
    Output *output;    


};

#endif
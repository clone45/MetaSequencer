#include "Arduino.h"
#include "Snapshot.h"

Snapshot::Snapshot(Memory *memory)
{
  this->memory = memory;
}

void Snapshot::init()
{
  uint8_t low_byte;
  uint8_t high_byte;

  // Load sequence from non-volitile ram
  for(int i=0; i<MAX_SEQUENCE_LENGTH; i++)
  {
    uint16_t memory_address = i * 2;

    low_byte = memory->read(memory_address);
    high_byte = memory->read(memory_address + 1);

    this->sequence[i] = word(high_byte, low_byte);
  }

  // Load sequence length
  low_byte = memory->read(MEM_ADDR_SEQUENCE_LENGTH);
  high_byte = memory->read(MEM_ADDR_SEQUENCE_LENGTH + 1);
  this->sequence_length = word(high_byte, low_byte);

  // Load clock division
  low_byte = memory->read(MEM_ADDR_CLOCK_DIVISION);
  high_byte = memory->read(MEM_ADDR_CLOCK_DIVISION + 1);
  this->clock_division = word(high_byte, low_byte);

  // Load slip
  this->slip = memory->read(MEM_ADDR_SLIP);

  // Load drift percentage
  this->drift_percentage = memory->read(MEM_ADDR_DRIFT_PERCENTAGE); 

  // Load drift amount
  low_byte = memory->read(MEM_ADDR_DRIFT_AMOUNT);
  high_byte = memory->read(MEM_ADDR_DRIFT_AMOUNT + 1);
  this->drift_amount = word(high_byte, low_byte);

  // Load hold pattern
  this->hold = memory->read(MEM_ADDR_HOLD);	

  // Load display intensity
  this->display_intensity = memory->read(MEM_ADDR_INTENSITY);  

  // Load scale
  this->scale = memory->read(MEM_ADDR_SCALE);

  // Load hold
  this->hold = memory->read(MEM_ADDR_HOLD); 

  // Load hold offset
  this->hold_offset = memory->read(MEM_ADDR_HOLD_OFFSET); 

  // Load hold threshold
  low_byte = memory->read(MEM_ADDR_HOLD_THRESHOLD);
  high_byte = memory->read(MEM_ADDR_HOLD_THRESHOLD + 1);
  this->hold_threshold = word(high_byte, low_byte);

  // Load song1 and song2
  this->song = memory->read(MEM_ADDR_SONG);  
  this->song2 = memory->read(MEM_ADDR_SONG2); 

  // Load reset input assignment
  this->rst_input_assignment = memory->read(MEM_RST_INPUT_ASSIGNMENT);

  // Load press functionality
  this->press_functionality = memory->read(MEM_PRESS_FUNCTIONALITY);
}



//
// setValue
//

void Snapshot::setValue(uint16_t step, uint16_t value)
{
  if(value != this->sequence[step])
  {
    // Write the value to the sequence array
    this->sequence[step] = value;

    // Also store the value in non-volitile memory
    uint16_t memory_address = step * 2;

    memory->write(memory_address, lowByte(value));
    memory->write(memory_address + 1, highByte(value));
  }
}

//
// Sequence Length
//

void Snapshot::setSequenceLength(uint16_t sequence_length)
{
  if(sequence_length != this->sequence_length)
  {
    this->sequence_length = sequence_length;
    memory->write(MEM_ADDR_SEQUENCE_LENGTH, lowByte(sequence_length));
    memory->write(MEM_ADDR_SEQUENCE_LENGTH + 1, highByte(sequence_length));
  }
}

//
// Clock Division
//

void Snapshot::setClockDivision(uint16_t clock_division)
{
  if(clock_division != this->clock_division)
  {
    this->clock_division = clock_division;
    memory->write(MEM_ADDR_CLOCK_DIVISION, lowByte(clock_division));
    memory->write(MEM_ADDR_CLOCK_DIVISION + 1, highByte(clock_division));    
  }
}

//
// Slip
//

void Snapshot::setSlip(uint8_t slip)
{
  if(slip != this->slip)
  {
    this->slip = slip;
    memory->write(MEM_ADDR_SLIP, slip);
  }
}

//
// Drift Percentage
//

void Snapshot::setDriftPercentage(uint8_t drift_percentage)
{
  if(drift_percentage != this->drift_percentage)
  {
    this->drift_percentage = drift_percentage;
    memory->write(MEM_ADDR_DRIFT_PERCENTAGE, drift_percentage);
  }
}

//
// Drift Amount
//

void Snapshot::setDriftAmount(uint16_t drift_amount)
{
  if(drift_amount != this->drift_amount)
  {
    this->drift_amount = drift_amount;
    memory->write(MEM_ADDR_DRIFT_AMOUNT, lowByte(drift_amount));
    memory->write(MEM_ADDR_DRIFT_AMOUNT + 1, highByte(drift_amount));    
  }
}

//
// Hold
//

void Snapshot::setHold(uint8_t hold)
{
  if(hold != this->hold)
  {
    this->hold = hold;
    memory->write(MEM_ADDR_HOLD, hold);
  }
}

//
// Hold Offset
//

void Snapshot::setHoldOffset(uint16_t hold_offset)
{
  if(hold_offset != this->hold_offset)
  {
    this->hold_offset = hold_offset;
    memory->write(MEM_ADDR_HOLD_OFFSET, hold_offset);
  }
}

//
// Hold Threshold
//

void Snapshot::setHoldThreshold(uint16_t hold_threshold)
{
  if(hold_threshold != this->hold_threshold)
  {
    this->hold_threshold = hold_threshold;
    memory->write(MEM_ADDR_HOLD_THRESHOLD, lowByte(hold_threshold));
    memory->write(MEM_ADDR_HOLD_THRESHOLD+1, highByte(hold_threshold));
  }
}

//
// Display Intensity
//

void Snapshot::setDisplayIntensity(uint8_t display_intensity)
{
  if(display_intensity != this->display_intensity)
  {
    this->display_intensity = display_intensity;
    memory->write(MEM_ADDR_INTENSITY, display_intensity);
  }
}

//
// Scale
//

void Snapshot::setScale(uint8_t scale)
{
	if(scale != this->scale)
	{
		this->scale = scale;
		memory->write(MEM_ADDR_SCALE, scale);
	}
}


//
// Song
//

void Snapshot::setSong(uint16_t song)
{
	if(song != this->song)
	{
		this->song = song;
		memory->write(MEM_ADDR_SONG, song);
	}
}

//
// Song2
//

void Snapshot::setSong2(uint16_t song2)
{
  if(song2 != this->song2)
  {
    this->song2 = song2;
    memory->write(MEM_ADDR_SONG2, song2);
  }
}

//
// rst_input_assignment
//

void Snapshot::setRstInputAssignment(uint8_t rst_input_assignment)
{
  if(rst_input_assignment != this->rst_input_assignment)
  {
    this->rst_input_assignment = rst_input_assignment;
    memory->write(MEM_RST_INPUT_ASSIGNMENT, rst_input_assignment);
  }
}

//
// press functionality (course/fine)
//

void Snapshot::setPressFunctionality(uint8_t press_functionality)
{
  if(press_functionality != this->press_functionality)
  {
    this->press_functionality = press_functionality;
    memory->write(MEM_PRESS_FUNCTIONALITY, press_functionality);
  }
}
#include "Arduino.h"
#include "Sequencer.h"

Sequencer::Sequencer()
{
}

void Sequencer::init()
{
  // Clear drift array
  memset(this->drift, 0, sizeof(this->drift));
}

void Sequencer::resetDrift()
{
  memset(this->drift, 0, sizeof(this->drift));
}
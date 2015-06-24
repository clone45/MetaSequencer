/*
             _          __                                           
  /\/\   ___| |_ __ _  / _\ ___  __ _ _   _  ___ _ __   ___ ___ _ __ 
 /    \ / _ \ __/ _` | \ \ / _ \/ _` | | | |/ _ \ '_ \ / __/ _ \ '__|
/ /\/\ \  __/ || (_| | _\ \  __/ (_| | |_| |  __/ | | | (_|  __/ |   
\/    \/\___|\__\__,_| \__/\___|\__, |\__,_|\___|_| |_|\___\___|_|   
                                   |_|                               
                                                         // by microbe modular
// =============================================================================
       
Copyright 2014 Bret Truchan / John Staskevich

  The Meta Sequencer source code is free software: you can redistribute it 
  and/or modify it under the terms of the GNU General Public License as 
  published by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Written for the Arduino Nano

Credits:
  Circuit/PCB design, parts selection, and manufacturing oversight by John Staskevich
  Front panel design by Hannes Pasqualini

Parts:
  DAC: MCP4725 - http://www.adafruit.com/datasheets/mcp4725.pdf
  LED Driver: AS1115 - http://www.ams.com/eng/content/download/18430/343782

Upcoming feature ideas / requests:  
  - allow reversing of the course/fine modes via a menu settings

Bugs
  - 

  
// =========================== - 80 column - ===================================
12345678901234567890123456789012345678901234567890123456789012345678901234567890

*/

#include <Wire.h>
#include "GlobalScales.h"
#include "Engine.h"

Engine *engine = new Engine();

void setup() 
{
  // set unused pins as outputs to prevent floating
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
  engine->init();
}

void loop() 
{
  engine->loop();
}
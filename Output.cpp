#include "Arduino.h"
#include "Output.h"


Output::Output(uint8_t i2c_address, Snapshot *snapshot, Transposer *transposer, Transposer *transposer2)
{
	this->i2c_address = i2c_address;
	this->snapshot = snapshot;
	this->transposer = transposer;
	this->transposer2 = transposer2;
}

void Output::write(uint16_t value)
{
	value = transposer->transpose(value, this->snapshot->song);
	value = transposer2->transpose(value, this->snapshot->song2);
	value = quantize(value);

	// Send information to DAC (MCP4725)
	Wire.beginTransmission(i2c_address);
	Wire.write(0x40); // Write command
	Wire.write(value / 16);
	Wire.write((value % 16) << 4);
	Wire.endTransmission();
}


uint16_t Output::quantize(uint16_t value)
{

	// The NOTES array and scale arrays are defined in GlobalScales.h/GlobalScales.cpp

	switch(this->snapshot->scale) {
		case 0:
			return(value); // no quantization
		case 1:
			value = map(value, 0, 4095, 0, 15);
			return(NOTES[MAJOR[value]]);		
		case 2:
			value = map(value, 0, 4095, 0, 15);
			return(NOTES[MINOR[value]]);
		case 3:
			value = map(value, 0, 4095, 0, 36);
			return(NOTES[IONIAN[value]]);		
		case 4:
			value = map(value, 0, 4095, 0, 35);
			return(NOTES[DORIAN[value]]);		
		case 5:
			value = map(value, 0, 4095, 0, 35);
			return(NOTES[LYDIAN[value]]);		
		case 6:
			value = map(value, 0, 4095, 0, 35);
			return(NOTES[PHRYGIAN[value]]);					
		case 7:
			value = map(value, 0, 4095, 0, 35);
			return(NOTES[MIXOLYDIAN[value]]);		
		case 8:
			value = map(value, 0, 4095, 0, 35);
			return(NOTES[AEOLIAN[value]]);		
		case 9:
			value = map(value, 0, 4095, 0, 35);
			return(NOTES[LOCRIAN[value]]);		
		case 10:
			value = map(value, 0, 4095, 0, 25);
			return(NOTES[MAJOR_PENTATONIC[value]]);		
		case 11:
			value = map(value, 0, 4095, 0, 25);
			return(NOTES[MINOR_PENTATONIC[value]]);		
		case 12:
			value = map(value, 0, 4095, 0, 40);
			return(NOTES[DIMINISHED[value]]);
		case 13:
			value = map(value, 0, 4095, 0, 60);
			return(NOTES[CHROMATIC[value]]);
		case 14:
			if(value >= 2048) return(4095);
			return(0);
	}	
}
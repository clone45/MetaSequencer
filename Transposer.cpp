#include "Arduino.h"
#include "Transposer.h"
#include "GlobalScales.h"


Transposer::Transposer(Snapshot *snapshot)
{
	this->snapshot = snapshot;
}

void Transposer::clock()
{
	this->clock_counter += 1;

	if(this->clock_counter == this->clock_division)
	{
		this->clock_counter = 0;
		this->step();
	}
}

void Transposer::step()
{
	this->pattern_step += 1;
	if(this->pattern_step == 16) this->pattern_step = 0;
}

void Transposer::reset()
{
	this->pattern_step = 0;
	this->clock_counter = 0;
}

uint16_t Transposer::transpose(int16_t note_to_transpose, uint8_t song)
{
	int table_index = TRANSPOSITION_TABLES[song][this->pattern_step];
	int tranpose_amount = 0;

	if(table_index < 0)
	{
		tranpose_amount = (int) NOTES[abs(table_index)] * -1;
	}
	else
	{
		tranpose_amount = (int) NOTES[table_index];
	}

	int transposed_value = (int) note_to_transpose + tranpose_amount;

	if(transposed_value > 4095) transposed_value = 4095 - transposed_value;
	if(transposed_value < 0) transposed_value = -1 * transposed_value;

	transposed_value = constrain(transposed_value, 0, 4095);

	return(transposed_value);
}

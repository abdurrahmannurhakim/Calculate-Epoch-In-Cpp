//============================================================================
// Name        : EpochCalculation.h
// Author      : Abdurrahman Nurhakim
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Calculate Epoch in C++
//============================================================================

#include <stdlib.h>
#include <stdint.h>

struct Time_form {
	uint16_t year;
	uint16_t month;
	uint16_t day;
	uint16_t hour;
	uint16_t minute;
	uint16_t second;
	uint16_t day_of_week;

};

class EpochCalculation {
public:
	EpochCalculation();
	void EpochCalculateDatelInput(uint16_t year, uint16_t month, uint16_t day,
			uint16_t hour, uint16_t minute, uint16_t second,
			unsigned int *output);
	void EpochCalculateStructInput(struct Time_form TimeForm, unsigned int *output);
};

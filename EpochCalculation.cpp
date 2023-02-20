//============================================================================
// Name        : EpochCalculation.cpp
// Author      : Abdurrahman Nurhakim
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Calculate Epoch in C++
//============================================================================

#include <stdio.h>
#include <string.h>
#include <EpochCalculation.h>

EpochCalculation::EpochCalculation(){

}

void EpochCalculation::EpochCalculateStructInput (struct Time_form TimeForm, unsigned int *output){
    // Parse date and time from string
	char* date_time_str;
    sscanf(date_time_str, "%d-%d-%d %d:%d:%d", &TimeForm.year, &TimeForm.month, &TimeForm.day, &TimeForm.hour, &TimeForm.minute, &TimeForm.second);

    // Calculate number of seconds between epoch and input date
    int num_leap_years = (TimeForm.year - 1969) / 4;
    int num_non_leap_years = TimeForm.year - 1970 - num_leap_years;
    int total_seconds = num_non_leap_years * 31536000 + num_leap_years * 31622400;

    int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int is_leap_year = (TimeForm.year % 4 == 0) && ((TimeForm.year % 100 != 0) || (TimeForm.year % 400 == 0));
    if (is_leap_year) {
        month_days[1] = 29;
    }

    int i;
    for (i = 0; i < TimeForm.month - 1; i++) {
        total_seconds += month_days[i] * 86400;
    }
    total_seconds += (TimeForm.day - 1) * 86400 + TimeForm.hour * 3600 + TimeForm.minute * 60 + TimeForm.second;

    *output = total_seconds;
}


void EpochCalculation::EpochCalculateDatelInput(uint16_t year, uint16_t month, uint16_t day,
		uint16_t hour, uint16_t minute, uint16_t second,
		unsigned int *output) {
    // Parse date and time from string
	char* date_time_str;
    sscanf(date_time_str, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    // Calculate number of seconds between epoch and input date
    int num_leap_years = (year - 1969) / 4;
    int num_non_leap_years = year - 1970 - num_leap_years;
    int total_seconds = num_non_leap_years * 31536000 + num_leap_years * 31622400;

    int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int is_leap_year = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
    if (is_leap_year) {
        month_days[1] = 29;
    }

    int i;
    for (i = 0; i < month - 1; i++) {
        total_seconds += month_days[i] * 86400;
    }
    total_seconds += (day - 1) * 86400 + hour * 3600 + minute * 60 + second;

    *output = total_seconds;
}


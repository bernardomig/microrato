#ifndef SENSORS_H
#define SENSORS_H

#include "mr32.h"

typedef enum
{
	ALL_OFF       = 0b00000,
	ALL_ON        = 0b11111,
	ON_TRACK	  = 0b00100,
	RIGHT_TILTED  = 0b00010,
	LEFT_TILTED   = 0b01000,
	RIGHT         = 0b00001,
	LEFT          = 0b10000
} sout;

sout sensors_get();


#endif

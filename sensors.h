#ifndef SENSORS_H
#define SENSORS_H

#include "mr32.h"

typedef enum
{
	ALL_OFF,
	ALL_ON,
	ON_TRACK,
	RIGHT_TILTED,
	LEFT_TILTED,
	RIGHT,
	LEFT
} sout;

inline unsigned int sensors_getRAW();

sout sensors_get();


#endif

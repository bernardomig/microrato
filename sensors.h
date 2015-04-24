#ifndef SENSORS_H
#define SENSORS_H

#include "mr32.h"

typedef enum
{
	OUT_OF_TRACK,
	ALL_ON,
	ON_TRACK,
	RIGHT_TILTED,
	LEFT_TILTED,
	RIGHT_TRACK,
	LEFT_TRACK
} Output;

inline unsigned int sensor_getRAW();

Output sensor_get();


#endif

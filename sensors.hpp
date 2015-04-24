#ifndef SENSORS
#define SENSORS

#include "mr32.h"

namespace sensors
{

const int gain = 0;

enum Output
{
	OUT_OF_TRACK,
	ALL_ON,
	ON_TRACK,
	RIGHT_TILTED,
	LEFT_TILTED,
	RIGHT_TRACK,
	LEFT_TRACK
};

inline unsigned int getRAW();

Output get();

}

#endif
#include "sensors.h"

const int gain = 0;

sout sensors_get()
{
	return (readLineSensors(gain) & 0b11111);
}

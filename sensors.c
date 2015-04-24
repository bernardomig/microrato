#include "sensors.h"

const int gain = 0;

unsigned int sensors_getRAW()
{
	return readLineSensors(gain);
}

sout sensors_get()
{
	int read = (readLineSensors(gain) & 0b11111);
	if(read == 0b00000)
		return ALL_OFF;
	else if(read == 0b11111)
		return ALL_ON;
	else if(read & 0b10000)
		return LEFT;
	else if(read & 0b00001)
		return RIGHT;
	else if(read & 0b00100)
		return ON_TRACK;
	else if(read & 0b00010)
		return RIGHT_TILTED;
	else if(read & 0b01000)
		return LEFT_TILTED;
	else
		return 0;
}

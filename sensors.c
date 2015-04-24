#include "sensors.h"

const int gain = 0;

unsigned int sensor_getRAW()
{
	return readLineSensors(gain);
}

sout sensor_get()
{
	int read = (readLineSensors(gain) | 0b11111);
	if(read == 0b00000)
		return OUT_OF_TRACK;
	else if(read == 0b11111)
		return ALL_ON;
	else if(read == 0b01100 || read == 0b01000)
		return LEFT_TILTED;
	else if(read == 0b00110 || read == 0b00010)
		return RIGHT_TILTED;
	else if(read & 0b10000)
		return LEFT;
	else if(read & 0b00001)
		return RIGHT;
	else
		return 0;
}

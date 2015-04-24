#include "sensors.hpp"

int readLineSensors(int x) { return 0;};

namespace sensors
{

unsigned int getRAW()
{
	return readLineSensors(gain);
}

Output get()
{
	int read = readLineSensors(gain);
	if(read == 0b00000)
		return OUT_OF_TRACK;
	else if(read == 0b11111)
		return ALL_ON;
	else if(read == 0b01100 || read == 0b01000)
		return RIGHT_TILTED;
	else if(read == 0b00110 || read == 0b00010)
		return RIGHT_TILTED;
	else if(read == 0b01110 || read == 0b01110)
		return ON_TRACK;
	else if(read & 0b10000)
		return RIGHT_TRACK;
	else if(read & 0b00001)
		return LEFT_TRACK;
}

}
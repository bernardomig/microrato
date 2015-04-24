#include "moviment.h" 

void moviment_rotate90right()
{
	motors_rotateRight();
	while(sensors_get() != RIGHT);
	while(sensors_get() != ON_TRACK);
}

void moviment_rotate90Left()
{
	motors_rotateLeft();
	while(sensors_get() != LEFT);
	while(sensors_get() != ON_TRACK);
}

void moviment_forward()
{
	if(sensors_get() == ON_TRACK)
		motors_forward();
	else if (sensors_get() == RIGHT_TILTED)
		motors_forwardLeft();
	else if (sensors_get() == LEFT_TILTED)
		motors_forwardRight();
}

void moviment_rotate180()
{
	motors_rotateRight();
	while(sensors_get() != RIGHT);
	while(sensors_get() != ON_TRACK);
}

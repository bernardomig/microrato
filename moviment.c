#include "moviment.h"

void moviment_align()
{
	if(sensors_get() & LEFT_TILTED) {
		motors_rotateRight();
		while(!(sensors_get() & ON_TRACK));
	}
	else if(sensors_get() & RIGHT_TILTED) {
		motors_rotateLeft();
		while(!(sensors_get() & ON_TRACK));
	}
}

void moviment_rotate90Right()
{
	motors_rotateRight();
	if(sensors_get() & ON_TRACK) {
		while(sensors_get() & ON_TRACK);
	}
	while(!(sensors_get() & ON_TRACK));
	motors_stop();
}

void moviment_rotate90Left()
{
	motors_rotateLeft();
	while(sensors_get() & ON_TRACK);
	while(!(sensors_get() & ON_TRACK));
	motors_stop();
}

void moviment_forward()
{
	if(sensors_get() & ON_TRACK)
		motors_forward();
	else if (sensors_get() & RIGHT_TILTED)
		motors_forwardRight();
	else if (sensors_get() & LEFT_TILTED)
		motors_forwardLeft();
}

void moviment_rotate180()
{
	motors_rotateRight();
	if(!(sensors_get() & RIGHT)) {
		while(!(sensors_get() & RIGHT));
	}
	while(!(sensors_get() & ON_TRACK));
	motors_stop();
}

void moviment_stop()
{
	motors_stop();
}

void moviment_back()
{
	motors_back();
}

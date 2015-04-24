#include "motors.hpp"

namespace motors
{

void stop()
{
	setVel2(0, 0);
}

void forward()
{
	setVel2(max_speed, max_speed);
}


void back()
{
	setVel2(-max_speed, -max_speed);
}


void rotateRight()
{
	setVel2(max_speed, -max_speed);
}


void rotateLeft()
{
	setVel2(-max_speed, max_speed);
}


void forwardLeft()
{
	setVel2(0, max_speed);
}

void forwardRight()
{
	setVel2(max_speed, 0);
}

void backLeft()
{
	setVel2(0, -max_speed);
}

void backRight()
{
	setVel2(-max_speed, 0);
}

}
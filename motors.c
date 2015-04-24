#include "motors.h"

const int max_speed = 100;

void motors_stop()
{
	setVel2(0, 0);
}

void motors_forward()
{
	setVel2(max_speed, max_speed);
}


void motors_back()
{
	setVel2(-max_speed, -max_speed);
}


void motors_rotateRight()
{
	setVel2(max_speed, -max_speed);
}


void motors_rotateLeft()
{
	setVel2(-max_speed, max_speed);
}


void motors_forwardLeft()
{
	setVel2(0, max_speed);
}

void motors_forwardRight()
{
	setVel2(max_speed, 0);
}

void motors_backLeft()
{
	setVel2(0, -max_speed);
}

void motors_backRight()
{
	setVel2(-max_speed, 0);
}

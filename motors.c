#include "motors.h"


void motors_stop()
{
	setVel2(0, 0);
}

void motors_forward()
{
	setVel2(LINEAR_SPEED, LINEAR_SPEED);
}


void motors_back()
{
	setVel2(-HALF_LINEAR_SPEED, -HALF_LINEAR_SPEED/2);
}


void motors_rotateRight()
{
	setVel2(ROTATE_SPEED, -ROTATE_SPEED);
}


void motors_rotateLeft()
{
	setVel2(-ROTATE_SPEED, ROTATE_SPEED);
}


void motors_forwardLeft()
{
	setVel2(0, ROTATE_SPEED);
}

void motors_forwardRight()
{
	setVel2(ROTATE_SPEED, 0);
}

void motors_backLeft()
{
	setVel2(0, -ROTATE_SPEED);
}

void motors_backRight()
{
	setVel2(-ROTATE_SPEED, 0);
}

#ifndef MOTORS_H
#define MOTORS_H

#include "mr32.h"

#define LINEAR_SPEED 90
#define HALF_LINEAR_SPEED 80
#define ROTATE_SPEED 70

void motors_stop();

void motors_forward();

void motors_back();

void motors_rotateRight();

void motors_rotateLeft();

void motors_forwardRight();

void motors_forwardLeft();

void motors_backRight();

void motors_backLeft();

#endif

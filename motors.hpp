#ifndef MOTORS
#define MOTORS

#include "mr32.h"

namespace motors
{

const int max_speed = 100;

void stop();

void forward();

void back();

void rotateRight();

void rotateLeft();

void forwardRight();

void forwardLeft();

void backRight();

void backLeft();

}

#endif

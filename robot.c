#include "robot.h"

void robot_init()
{
	initPIC32();
	closedLoopControl( FALSE );
}

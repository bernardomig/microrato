#ifndef INTERSECTIONS_H
#define INTERSECTIONS_H

#include "directions.h"

typedef enum
{
	CROSS,
	T_TURN,
	FRONT_LEFT,
	FRONT_RIGHT,
} Intersections;

int Intersections_getMax(Intersections);
Directions Intersections_get(Intersections, int);

#endif

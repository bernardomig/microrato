#include "intersections.h"

int Intersections_getMax(Intersections i)
{
	switch(i) {
		case CROSS: return 3;
		case T_TURN: return 2;
		case FRONT_LEFT: return 2;
		case FRONT_RIGHT: return 2;
	}
	return 0;
}

const Directions __cross__directions[] = {LEFT, RIGHT, FRONT};
const Directions __t_turn__directions[] = {LEFT, RIGHT};
const Directions __front_left__directions[] = {LEFT, FRONT};
const Directions __front_right__directions[] = {RIGHT, FRONT};


Directions Intersections_get(Intersections i, int n)
{
	switch(i) {
		case CROSS: return __cross__directions[n];
		case T_TURN: return __t_turn__directions[n];
		case FRONT_LEFT: return __front_left__directions[n];
		case FRONT_RIGHT: return __front_right__directions[n];
	}
	return 0;
}

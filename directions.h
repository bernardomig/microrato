#ifndef DIRECTIONS_H
#define DIRECTIONS_H

typedef enum
{
	LEFT,
	RIGHT,
	FRONT,
	BACK
} Directions;

Direction Direction_changeRef(Direction, Direction);

#endif

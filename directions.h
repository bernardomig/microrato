#ifndef DIRECTIONS_H
#define DIRECTIONS_H

typedef enum
{
	LEFT_DIR,
	RIGHT_DIR,
	FRONT_DIR,
	BACK_DIR
} Directions;

Directions Directions_changeRef(Directions, Directions);

#endif

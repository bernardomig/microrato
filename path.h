#ifndef PATH_H
#define PATH_H

#include "node.h"
#include "directions.h"
#include "intersections.h"
#include "mr32.h"

typedef struct
{
	Node nodes[100];
	int current;
	BOOL back;
} Path;

Path Path_new();

Directions Path_intersection(Path*, Intersections);

void Path_back(Path*);


#endif

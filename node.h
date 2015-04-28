#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

#include "directions.h"
#include "intersections.h"

typedef struct Node {
	int current;
	Intersections intersection;
} Node;

void Node_new(Node*, Intersections);
Directions Node_current(Node*);
Directions Node_next(Node*);

#endif

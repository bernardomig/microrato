#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

#include "directions.h"
#include "intersections.h"

typedef struct Node {
	struct Node* parent;
	int current;
	Intersections intersection;
} Node;

Node* Node_new(Node*, Intersections);
void Node_free(Node*);
Directions Node_current(Node*);
Directions Node_next(Node*);
Node* Node_parent(Node*);

#endif

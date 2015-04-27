#include "node.h"

Node* Node_new(Node* p, Intersections i)
{
	Node* self = malloc(sizeof(Node));
	self->current = 0;
	p->child = self;
	self->parent = p;
	self->intersection = i;
	return self;
}

void Node_free(Node* self)
{
	free(self);
}

Directions Node_current(Node* self)
{
	return Intersections_get(self->intersection, self->current);
}

Directions Node_next(Node* self)
{
	if(self->current < Intersections_getMax(self->intersection))
	{
		self->current += 1;
		return Node_current(self);
	}
	else
	{
		return BACK;
	}
}

Node* Node_parent(Node* self)
{
	return self->parent;
}

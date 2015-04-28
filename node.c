#include "node.h"

#include "mr32.h"

void Node_new(Node* self, Intersections i)
{
	self->intersection = i;
	self->current = 0;
}

Directions Node_current(Node* self)
{
	return Intersections_get(self->intersection, self->current);
}

Directions Node_next(Node* self)
{
	self->current += 1;
	if(self->current < Intersections_getMax(self->intersection))
	{
		return Node_current(self);
	}
	else
	{
		return BACK_DIR;
	}
}

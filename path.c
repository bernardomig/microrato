#include "path.h"

Path Path_new()
{
	Path self;
	self.current = 0;
	self.back = FALSE;
	self.is_complete = FALSE;
	return self;
}

Directions Path_intersection(Path* self, Intersections i)
{
	if(self->is_complete)
	{
		self->current += 1;
		Directions d = Node_current(self->nodes + self->current);
		return d;
	}
	if(self->back) {
		self->back = FALSE;
		Directions c = Node_current(self->nodes + self->current);
		Directions d = Node_next(self->nodes + self->current);
		if(d == BACK_DIR)
		{
			self->current -= 1;
			self->back = TRUE;
			return Directions_changeRef(c, BACK_DIR);
		}
		else
			return Directions_changeRef(c, d);
	}
	else {
		self->current += 1;
		Node_new(self->nodes + self->current, i);
		return Node_current(self->nodes + self->current);
	}
}

void Path_back(Path* self) 
{
	self->back = TRUE;
}


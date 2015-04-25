#include "path.h"

Path Path_new()
{
	Path self;
	self.current = NULL;
	self.back == false;
	return self;
}

Direction Path_Intersection(Path* self, Intersection i)
{
	if(self->back == false) {
		Node* next = Node_new(self->current)
	}
}
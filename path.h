#ifndef PATH_H
#define PATH_H

#include "node.h"

typedef struct Path
{
	Node* current;
	bool back;
} Path;

Path Path_new();

Direction Path_Intersection(Intersection);




#endif

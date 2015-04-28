#include "mr32.h"
#include "robot.h"
#include "moviment.h"
#include "sensors.h"
#include "path.h"

void Print_Path(Path* self) {
	printf("%s\n", "========================================");
	Node* n = self->current;
	while(n) {
		if(n->intersection == CROSS)
			printf("CROSS\n");
		else if(n->intersection == T_TURN)
			printf("T_TURN\n");
		else if(n->intersection == FRONT_LEFT)
			printf("FRONT_LEFT\n");
		else if(n->intersection == FRONT_LEFT)
			printf("FRONT_LEFT\n");
	}
	printf("%s\n", "========================================");
}

int main()
{
	int* i = malloc(sizeof(int));

	*i = 9;

	printf("%i\n", *i);

	return 0;
}
#include "mr32.h"
#include "robot.h"
#include "moviment.h"
#include "sensors.h"
#include "path.h"

void printPath(Path* path)
{
	printf("%s\n", "======================");
	int i;
	for(i = 0; i <= path->current; ++i) {
		if(path->nodes[i].intersection == CROSS) {
			printf("%s\n", "CROSS");
		}
		else if(path->nodes[i].intersection == T_TURN) {
			printf("%s\n", "T_TURN");
		}
		else if(path->nodes[i].intersection == FRONT_RIGHT) {
			printf("%s\n", "FRONT_RIGHT");
		}
		else if(path->nodes[i].intersection == FRONT_LEFT) {
			printf("%s\n", "FRONT_LEFT");
		}
	} 
	if(path->back)
	printf("%s\n", "GOING BACK");
}

void move(Directions d) {
	if(d == RIGHT_DIR)
	{
		//printf("%s\n", "GOING Right");
		moviment_rotate90Right();
	}
	else if(d == LEFT_DIR){
		//printf("%s\n", "GOING LEFT");
		moviment_rotate90Left();
	}
	else if(d == FRONT_DIR) {
		//printf("%s\n", "GOING Front");
		moviment_forward();
	}
}

int main()
{
	sout s, p;
	Path path = Path_new();
	
	robot_init();
	while(1) {
		while(!startButton());
		moviment_forward();
		while(!stopButton()) {
			if(sensors_get() == s)
				continue;

			p = s;
			s = sensors_get();

			if((s & LEFT) && (s & RIGHT) && !path.is_complete) {
				delay(800);
				sout t = sensors_get();
				if((t & LEFT) && (t & RIGHT)) { 
					moviment_stop();
					path.current = 0;
					path.is_complete = 1;
					p = s = 0;
					
					break;
				}
			}

			if((p & LEFT) && (p & RIGHT) && (s & (LEFT|RIGHT))) {
				s |= (RIGHT|LEFT);
			}
			if (!(s & CENTERED))
			{
				s &= CENTERED;
			}

			if((s & CENTERED) && (p & CENTERED)) {
				// Continue the road
				moviment_forward();
			}
			if((p & RIGHT) && (p & LEFT) && !(s & RIGHT) && !(s & LEFT) && !(s & CENTERED)) {
				// T Shape	
				Directions d = Path_intersection(&path, T_TURN);
				move(d);
				printPath(&path);
				continue;
			}
			if((p & RIGHT) && (p & LEFT) && !(s & RIGHT) && !(s & LEFT) && (s & CENTERED)) {
				// CROSS Shape
				Directions d = Path_intersection(&path, CROSS);
				move(d);
				printPath(&path);
				continue;
			}
			if((p & RIGHT) && !(s & RIGHT) && !(p & LEFT) && !(s & LEFT) && (p & CENTERED) && !(s & CENTERED)) {
				// RIGHT TURN
				moviment_rotate90Right();
				continue;
			}
			if((p & LEFT) && !(s & LEFT) && !(p & RIGHT) && !(s & RIGHT) && (p & CENTERED) && !(s & CENTERED)) {
				// LEFT TURN
				moviment_rotate90Left();
				continue;
			}
			if((p & RIGHT) && !(s & RIGHT) && !(p & LEFT) && !(s & LEFT) && (s & CENTERED)) {
				// RIGHT_FRONT TURN
				Directions d = Path_intersection(&path, FRONT_RIGHT);
				printPath(&path);
				move(d);
				
				continue;
			}
			if((p & LEFT) && !(s & LEFT) && !(p & RIGHT) && !(s & RIGHT) && (s & CENTERED)) {
				// LEFT_FRONT TURN
				Directions d = Path_intersection(&path, FRONT_LEFT);
				printPath(&path);
				move(d);
				continue;
			}
			if((s == ALL_OFF) && (p & CENTERED)) {
				// End of the road
				moviment_rotate180();
				Path_back(&path);
				continue;
			}
		}
		moviment_stop();
	}
}

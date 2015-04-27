#include "mr32.h"
#include "robot.h"
#include "moviment.h"
#include "sensors.h"

int main()
{
	sout s, p;
	
	robot_init();
	while(1) {
		while(!startButton());
		while(!stopButton()) {
			p = s;
			s = sensors_get();
			if((s & ON_TRACK) && ((p & (RIGHT|LEFT)) == (RIGHT|LEFT))) {
				// Cross Intersection
				printf("%s\n", "Cross Intersection");
				leds(0b111);
			}
			else if((s & ON_TRACK) && (p & LEFT)) {
				// FRONT_LEFT Intersection
				printf("%s\n", "FRONT_LEFT Intersection");
				leds(0b110);

				motors_forwardLeft();
				while(sensors_get() & ON_TRACK);
				motors_rotateLeft();
				while(!(sensors_get() & ON_TRACK));	
				s = ON_TRACK;
			}
			else if((s & ON_TRACK) && (p & RIGHT)) {
				// FRONT_RIGHT Intersection
				printf("%s\n", "FRONT_RIGHT Intersection");
				leds(0b011);
				motors_forwardRight();
				while(sensors_get() & ON_TRACK);
				motors_rotateRight();
				while(!(sensors_get() & ON_TRACK));	
				s = ON_TRACK;
			}
			else if((s & (ON_TRACK|RIGHT_TILTED|LEFT_TILTED)) && (p & (ON_TRACK|RIGHT_TILTED|LEFT_TILTED))) {
				moviment_forward();
			}
			else if((s == ALL_OFF) && (p & RIGHT)) {
				// RIGHT Intersection
				printf("%s\n", "RIGHT Intersection");
				moviment_rotate90Right();
				leds(0b001);
			}
			else if((s == ALL_OFF) && (p & LEFT)) {
				// LEFT Intersection
				printf("%s\n", "LEFT Intersection");
				moviment_rotate90Left();
				leds(0b100);
			}
			else if((s == ALL_OFF) && (p & (ON_TRACK|RIGHT_TILTED|LEFT_TILTED))) {
				// DEADEND Intersection
				printf("%s\n", "DEADEND Intersection");
				leds(0b000);
				moviment_rotate180();
			}
			else if(!(s & ON_TRACK) && ((p & (RIGHT|LEFT)) == (RIGHT|LEFT))) {
				// T_TURN Intersection
				printf("%s\n", "T_TURN Intersection");
				moviment_rotate90Left();
				leds(0b101);
			}
			else {
				moviment_back();
			}
		}
		moviment_stop();
	}
}

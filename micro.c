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
			if(sensors_get() == s)
				continue;

			p = s;
			s = sensors_get();

			if((p & LEFT) && (p & RIGHT) && (s & (LEFT|RIGHT))) {
				s |= (RIGHT|LEFT);
			}
			if (!(s & CENTERED))
			{
				s &= CENTERED;
			}

			printf("Sensors: %u %u %u %u %u \n",
				(s & 0b10000) && 1,
				(s & 0b01000) && 1,
				(s & 0b00100) && 1,
				(s & 0b00010) && 1,
				(s & 0b00001) && 1);

			if((s & CENTERED) && (p & CENTERED)) {
				// Continue the road
				moviment_forward();
			}
			if((p & RIGHT) && (p & LEFT) && !(s & RIGHT) && !(s & LEFT) && !(s & CENTERED)) {
				// T Shape
				printf("T SHAPE\n");
				continue;
			}
			if((p & RIGHT) && (p & LEFT) && !(s & RIGHT) && !(s & LEFT) && (s & CENTERED)) {
				// CROSS Shape
				printf("CROSS\n");
				continue;
			}
			if((p & RIGHT) && !(s & RIGHT) && !(p & LEFT) && !(s & LEFT) && (p & CENTERED) && !(s & CENTERED)) {
				printf("%s\n", "RIGHT TURN");
				moviment_rotate90Right();
				continue;
			}
			if((p & LEFT) && !(s & LEFT) && !(p & RIGHT) && !(s & RIGHT) && (p & CENTERED) && !(s & CENTERED)) {
				printf("%s\n", "LEFT TURN");
				moviment_rotate90Left();
				continue;
			}
			if((p & RIGHT) && !(s & RIGHT) && !(p & LEFT) && !(s & LEFT) && (s & CENTERED)) {
				printf("%s\n", "FRONT RIGHT");
				moviment_rotate90Right();
				continue;
			}
			if((p & LEFT) && !(s & LEFT) && !(p & RIGHT) && !(s & RIGHT) && (s & CENTERED)) {
				printf("%s\n", "FRONT LEFT");
				moviment_rotate90Left();
				continue;
			}
			if((s == ALL_OFF) && (p & CENTERED)) {
				// End of the road
				moviment_rotate180();
				continue;
			}
		}
		moviment_stop();
	}
}

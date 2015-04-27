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
				leds(0b111);
			}
			else if((s & ON_TRACK) && (p & LEFT)) {
				leds(0b110);
			}
			else if((s & ON_TRACK) && (p & RIGHT)) {
				leds(0b011);
			}
			else if((s & (ON_TRACK|RIGHT_TILTED|LEFT_TILTED)) && (p & (ON_TRACK|RIGHT_TILTED|LEFT_TILTED))) {
				moviment_forward();
			}
			else if((s == ALL_OFF) && (p & RIGHT)) {
				moviment_rotate90Right();
				leds(0b001);
			}
			else if((s == ALL_OFF) && (p & LEFT)) {
				moviment_rotate90Left();
				leds(0b100);
			}
			else if((s == ALL_OFF) && (p & (ON_TRACK|RIGHT_TILTED|LEFT_TILTED))) {
				leds(0b000);
				moviment_rotate180();
			}
			else if(!(s & ON_TRACK) && ((p & (RIGHT|LEFT)) == (RIGHT|LEFT))) {
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

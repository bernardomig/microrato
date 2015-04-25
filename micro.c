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
			
			if(s == LEFT) {
				while(sensors_get() == LEFT);
				moviment_rotate90Left();
				leds(0b100);
			}
			else if(s == RIGHT) {
				while(sensors_get() == RIGHT);
				moviment_rotate90Right();
				leds(0b001);
			}
			else if(s == ALL_ON) {
				while(sensors_get() == ALL_ON);
				moviment_rotate90Left();
				leds(0b111);
			}
			else if(s == ALL_OFF && p == ON_TRACK) {
				moviment_rotate180();
				leds(0b101);
			}
			else if(s == ON_TRACK || s == LEFT_TILTED || s == RIGHT_TILTED) {
				moviment_forward();
				leds(0b010);
			}
			else {
				moviment_back();
				leds(0b000);
			}
		}
		moviment_stop();
	}
}

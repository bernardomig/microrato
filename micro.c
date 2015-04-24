#include "mr32.h"
#include "robot.h"
#include "motors.h"
#include "sensors.h"

int l = 0;

int main()
{
	robot_init();
	while(1) { 
		while(!startButton());
		while(!stopButton()) {
			int s = sensor_getRAW();
			l = 0;
			if(s & 0b00001)
				l |= 0b01;
			if(s & 0b10000)
				l |= 0b10;
			leds(l);
			
			
			if (s & 0b00001) {
				while(sensor_getRAW() & 0b00001)
					motors_forward;
				while((sensor_getRAW() & 0b00100))
					motors_rotateRight();
				while(!(sensor_getRAW() & 0b00100))
					motors_rotateRight();
			}
			else if (s & 0b10000) {
				while(sensor_getRAW() & 0b10000)
					motors_forward;
				while((sensor_getRAW() & 0b00100))
					motors_rotateLeft();
				while(!(sensor_getRAW() & 0b00100))
					motors_rotateLeft();
			}
			else if (s & 0b10001) {
				while(sensor_getRAW() & 0b10001)
					motors_forward;
				while(!(sensor_getRAW() & 0b00001))
					motors_rotateRight();
				while(!(sensor_getRAW() & 0b00100))
					motors_rotateRight();
			}
			else if(s & 0b00100)
				motors_forward();
			else if(s & 0b00010)
				motors_forwardRight();
			else if(s & 0b01000)
				motors_forwardLeft();
			else if(s == 0b00000){
				while(!(sensor_getRAW() & 0b00001))
					motors_rotateLeft();
			}
		}
		motors_stop();
	}
}

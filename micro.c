#include "mr32.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

int sensors, previous;

int main(void)
{
  initPIC32();
  
  closedLoopControl(false);
  enableObstSens();
  
  while(1) {
    while(!startButton());
    
    while(!stopButton()) {
      previous = sensors;
      sensors = readLineSensors(0);
      
      if((sensors & 0b11111) == 0) {
	leds(0b111);
	if(previous == 0b11111) {
	  setVel2(-100, 100);
	  delay(10000);
	}
	else
	   setVel2(-80, -80);
      }
      else if((sensors & 0b00100) != 0) {
	leds(0b010);
	setVel2(100,100);
      }
      else if((sensors & 0b10000) != 0) {
	leds(0b100);
	setVel2(-60, 60);
      }
      else if((sensors & 0b00001) != 0) {
	leds(0b001);
	setVel2(60, -60);
      }
      delay(50);
    }
    setVel2(0,0);
  }
}

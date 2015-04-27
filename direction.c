#include "direction.h"

Direction Direction_changeRef(Direction ref, Direction dir)
{
	switch(ref) {
		case BACK:
			return dir;
		case LEFT:
			switch(dir) {
				case BACK: return RIGHT;
				case LEFT: return BACK;
				case FRONT: return LEFT;
				case RIGHT: return FRONT;
			}
		case FRONT:
			switch(dir) {
				case BACK: return FRONT;
				case LEFT: return RIGHT;
				case FRONT: return BACK;
				case RIGHT: return LEFT;
			}
		case RIGHT:
			switch(dir) {
				case BACK: return LEFT;
				case LEFT: return FRONT;
				case FRONT: return RIGHT;
				case RIGHT: return BACK;
			}
	}
}
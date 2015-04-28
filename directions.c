#include "directions.h"

Directions Directions_changeRef(Directions ref, Directions dir)
{
	switch(ref) {
		case BACK_DIR:
			return dir;
		case LEFT_DIR:
			switch(dir) {
				case BACK_DIR: return RIGHT_DIR;
				case LEFT_DIR: return BACK_DIR;
				case FRONT_DIR: return LEFT_DIR;
				case RIGHT_DIR: return FRONT_DIR;
			}
		case FRONT_DIR:
			switch(dir) {
				case BACK_DIR: return FRONT_DIR;
				case LEFT_DIR: return RIGHT_DIR;
				case FRONT_DIR: return BACK_DIR;
				case RIGHT_DIR: return LEFT_DIR;
			}
		case RIGHT_DIR:
			switch(dir) {
				case BACK_DIR: return LEFT_DIR;
				case LEFT_DIR: return FRONT_DIR;
				case FRONT_DIR: return RIGHT_DIR;
				case RIGHT_DIR: return BACK_DIR;
			}
	}
	return BACK_DIR;
}

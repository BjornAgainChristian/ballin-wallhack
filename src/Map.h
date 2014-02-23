#ifndef _MAP_H_
#define _MAP_H_

typedef struct { //to test if the tile itself and surrounding can be walked on
	bool self;
	bool up;
	bool down;
	bool left;
	bool right;
} Walkable;

#endif

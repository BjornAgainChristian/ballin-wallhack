#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#define VERSION 0.01

using namespace std;

const int SCREEN_HARDCODE_WIDTH 	= 800;
const int SCREEN_HARDCODE_HEIGHT 	= 600;
const int SCREEN_HARDCODE_BPP		= 32;

const int FRAMES_PER_SECOND		= 30;

const int TILE_WIDTH			= 32;
const int TILE_HEIGHT			= 32;

const int X_HARDCODE_TILES_VIEWED	= 25;
const int Y_HARDCODE_TILES_VIEWED	= 18; //(actually 18.75 but whatever)

enum {
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef map<string, int> Coords; //used for player coords

#endif

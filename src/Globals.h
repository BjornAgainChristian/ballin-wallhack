#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#define VERSION 0.01

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int SCREEN_HARDCODE_WIDTH 	= 800;
const int SCREEN_HARDCODE_HEIGHT 	= 600;
const int SCREEN_HARDCODE_BPP		= 32;

const int FRAMES_PER_SECOND		= 30;

const int TILE_WIDTH			= 32;
const int TILE_HEIGHT			= 32;

const int X_HARDCODE_TILES_VIEWED	= 32;
const int Y_HARDCODE_TILES_VIEWED	= 24;

enum {
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct {
	vector<SDL_Surface*> Left;
	vector<SDL_Surface*> Right;
	vector<SDL_Surface*> Up;
	vector<SDL_Surface*> Down;
	SDL_Surface* Static;
} Sprite;

typedef map<string, int> Coords; //used for player coords

#endif

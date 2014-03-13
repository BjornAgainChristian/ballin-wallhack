#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL/SDL.h>
#include <vector>

#include "Globals.h"
#include "Map.h"
#include "Player.h"


class Screen
{
	public:
	Screen(Map map, Player mainPlayer);
	~Screen();

	void DrawIMG(SDL_Surface *img, int x, int y); //blit all
	void DrawIMG(SDL_Surface *img, int x, int y, int width, int height, int x2, int y2); //blit portion
	void DrawBackground(); //black background (layer 0)
	void DrawMap(); //draw maptiles (layer 1)
	void DrawSprites(); //draw sprites (layer 2)
	

	void DrawScene();

	void HandleKeys();

	void TestLoop();

	protected:

	bool Quit;

	SDL_Surface* _screen; //main screen
	SDL_Surface* _temp; //TODO remove after testing static, prior to anim

	Map* _map;
	Player* _mainPlayer;

};

#endif

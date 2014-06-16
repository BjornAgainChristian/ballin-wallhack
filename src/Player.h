#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Globals.h"

class Player
{
	public:
	Player(string name);
	~Player();

	void SetPosition(int x, int y);
	Coords GetPosition();
	void LoadAnimations();
	Sprite GetAnimations();

	protected:
	string Name;
	unsigned long long id; //id number

	Coords Position;
	Sprite Anim;
};


#endif

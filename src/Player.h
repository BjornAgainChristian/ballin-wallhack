#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

#include "Globals.h"

class Player
{
	public:
	Player(string name);
	~Player();

	void SetPosition(int x, int y);
	Coords GetPosition();

	protected:
	string Name;
	unsigned long long id; //id number

	Coords Position;
};


#endif

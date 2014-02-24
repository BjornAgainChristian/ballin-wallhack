#ifndef _MAP_H_
#define _MAP_H_

#include <string>
#include <fstream>

#include "Globals.h"

typedef struct { //to test if the tile itself and surrounding can be walked on
	bool self;
	bool up;
	bool down;
	bool left;
	bool right;
} Walkable;


class Map
{
	public:
	Map(string file);
	~Map();

	void LoadMap(string file);
	void LoadObj(string file);

	void SetWalkable(int x, int y, Walkable walkable);
	bool IsWalkable(int x, int y);
	bool IsWalkable(int x, int y, string side);

	void SetPlayer(int x, int y, Player* player);
	void MovePlayer(int x, int y, Player* player);

	protected:

	string Name;
	
	int _width;
	int _height;

	map<int, map<int, Walkable> > _walkable; //walkable tilemap
	map<int, map<int, Player*> > _players; //player locations
};

#endif

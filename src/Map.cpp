#include "Map.h"

Map::Map(string file)
{
	string map, obj = file;

	Name = file; //for displaying on screen (probably)

	map += ".map";
	obj += ".obj";

	this->LoadMap(map);
	this->LoadObj(obj);
}

Map::~Map()
{
	
}

void Map::LoadMap(string file)
{
	ifstream Input;
	Input.open(file.c_str());

	Input.close();
}

void Map::LoadObj(string file)
{
	ifstream Input;
	Input.open(file.c_str());

	Input.close();
}

bool Map::SetWalkable(int x, int y, Walkable, walkable)
{

}

bool Map::IsWalkable(int x, int y)
{
	//test map boundaries, return false if over
	if ((x < 0) || (y < 0) || (x >= this->_width) || (y >= this->_height))
	{
		return false;
	}
	return this->_walkable[x][y].self; //tile is walkable
}

bool Map::IsWalkable(int x, int y, string side)
{
	//testing map boundary
	if ((x < 0) || (y < 0) || (x >= this->_width) || (y >= this->_height))
	{
		return false;
	}

	//isn't over boundaries, return side
	if (side == "up") {
		return this->_walkable[x][y].up;
	}
	else if (side == "down") {
		return this->_walkable[x][y].down;
	}
	else if (side == "left") {
		return this->_walkable[x][y].left;
	}
	else if (side == "right") {
		return this->_walkable[x][y].right;
	}
	else { //all else fails, return self
		return this->_walkable[x][y].self;
	}
}

void Map::SetPlayer(int x, int y, Player* player)
{
	_players[x][y] = player;
}

void MovePlayer(int x, int y, Player* player)
{
	if ((x < 0) || (y < 0) || (x > this->_width) || (y > this->_height))
	{
		//TODO: throw error code here; outside out map boundary
	}

	Coord coords = player->GetPosition();
	//erase from old coord before moving
	this->_players[coords["x"]].erase(coords["y"]);

	this->_players[x][y] = player;
	player->SetPosition(x, y);
}

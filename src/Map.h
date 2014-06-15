#ifndef _MAP_H_
#define _MAP_H_

#include <string>
#include <fstream>
#include <vector>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Globals.h"
#include "Player.h"

typedef struct {
	int Anim; //animation frame count
	Coords coords; //x/y coords
	vector<int> Tiles; //animation tile numbers
	int Exit; //if the tile is an exit, set to number; else 0
} MapTile;

typedef struct {
	int Anim; //animation frame count
	Coords coords; //x/y coords
	vector<int> Frames; //animation frame numbers
	bool Collidable; //is object collidable?
	int Item; //0 = not an item; >0 = item number in dbase
	int Interactive; //0 = not interactive; >0 = event number in .event
	int Door; //0 = not a door; >0 = zone to exit to
	bool Hidden; //is item invisible or not
} MapObj;

class Map
{
	public:
	Map(string file);
	~Map();

	void LoadMap(string file);
	void LoadObj(string file);
	void LoadTiles(string file);

	bool IsCollidable(int x, int y); //for objects

	void SetPlayer(int x, int y, Player* player);
	void MovePlayer(int x, int y, Player* player);

	int GetWidth();
	int GetHeight();

	vector<MapTile> GetMapTile();
	vector<MapObj> GetMapObj();
	vector<SDL_Surface*> GetSDLTiles();

	protected:

	string Name;
	
	int _width;
	int _height;

	map<int, map<int, Player*> > _players; //player locations
	vector<MapTile> _map; //map information
	vector<MapObj> _obj; //objects/sprites 

	vector<SDL_Surface*> _tiles; //tile img information for rendering
};

#endif

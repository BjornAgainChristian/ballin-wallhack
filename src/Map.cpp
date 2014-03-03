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
	/* MAP STRUCTURE:
	
	Width
	Height
	
	@per tile:
	Animation flag (0 = no anim; >0 = anim frames)
	X coord on map
	Y coord on map
	Tile Numbers (if anim = 0 static tile, no anim; 
		if anim >0 read in all tile numbers for animation of the tile)
	Walkable structure (order: Self, Up, Down, Left, Right)
	Exit (if exit = 0, not an exit; >0 = exit into map number

	*/

	ifstream Input;
	Input.open(file.c_str());

	int temp, loop, x, y, pos; //pos is for array size, pushing to last element
	
	Walkable walkable; //populating walkable map

	Input >> this->_width;
	Input >> this->_height; //read in w/h first, then onto each element

	while (true)
	{
		this->_map.push_back();
		pos = (int)this->_map.size() - 1;
		
		Input >> this->_map[pos].Anim;

		Input >> this->_map[pos].coords["x"];
		x =  this->_map[pos].coords["x"];

		Input >> this->_map[pos].coords["y"];
		y = this->_map[pos].coords["y"];
		
		//now read in the tiles for anim
		for (loop = 0; loop <= Anim; loop++)
		{
			Input >> temp;
			this->_map[pos].Tiles.push_back(temp);
		}

		//now to populate the walkable map
		for (loop = 1; loop <= 5; loop++)
		{
			Input >> temp;
			switch(loop)
			{
				//set true/false based on 1/0 from file
				case 1: //self
					walkable.self = (temp > 0 ? true : false);
					break;
				case 2: //north
					walkable.up = (temp > 0 ? true : false);
					break;
				case 3: //south
					walkable.down = (temp > 0 ? true : false);
					break;
				case 4: //west
					walkable.left = (temp > 0 ? true : false);
					break;
				case 5: //east
					walkable.right = (temp > 0 ? true : false);
					break;
			}
		}

		//new walkable populated, set internal x,y walkable
		this->SetWalkable(x, y, walkable);
		//cleanup for next loop
		walkable.clear();

		//Input exit; >0 = exit number; 0 = not an exit
		Input >> this->_map[pos].Exit;

		//end of file, then break; end of map loader
		if (Input.eof) {
			break;
		}
	}

	Input.close();
}

void Map::LoadObj(string file)
{
	/* OBJ STRUCTURE
	
	Animation flag (0 = no anim; >0 = animation frame count)
	X map position
	Y map position
	Object animation Frames (use animation flag to read in amount)
	Collidable flag
	Item flag (0 = not an item; >0 = item number in dbase)
	Interactive flag (0 = not interactive; >0 = event number in .event
	Door flag (0 = not a door; >0 = zone to exit to)
	Hidden flag (boolean; 1 = true 0 = false from file)

	*/

	ifstream Input;
	Input.open(file.c_str());

	int temp, loop, pos;

	while (true)
	{
		this->_obj.push_back();
		pos = (int)this->_obj.size() - 1;

		Input >> this->_obj[pos].Anim;

		Input >> this->_obj[pos].coords["x"];
		Input >> this->_obj[pos].coords["y"];

		//load animation frames
		for (loop = 0; loop <= Anim; loop++)
		{
			Input >> temp;
			this->_obj[pos].Frames.push_back(temp);
		}

		//is object collidable? 1 = true, 0 = false
		Input >> temp;
		this->_obj[pos].collidable = (temp > 0 ? true : false);

		Input >> this->_obj[pos].Item;
		Input >> this->_obj[pos].Interactive;
		Input >> this->_obj[pos].Door;

		//is object hidden? 1 = true, 0 = false
		Input >> temp;
		this->_obj[pos].Hidden = (temp > 0 ? true : false);

		//end of reading in objects
		if (Input.eof())
		{
			break;
		}
	}

	Input.close();
}

bool Map::SetWalkable(int x, int y, Walkable, walkable)
{
	this _walkability[x][y] = walkable;
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

int Map::GetWidth()
{
	return this->_width;
}

int Map::GetHeight()
{
	return this->_height;
}

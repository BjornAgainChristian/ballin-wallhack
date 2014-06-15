#include "Map.h"

Map::Map(string file)
{
	string map, obj, tile;
	map = obj = tile = file;

	Name = file; //for displaying on screen (probably)

	map += ".map";
	obj += ".obj";
	tile += ".tile";

	this->LoadMap(map);
	this->LoadObj(obj);
	this->LoadTiles(tile);
}

Map::~Map()
{
	//free all SDL surfaces for clean shutdown
	for (int i; i < _tiles.size(); i++)
	{
		SDL_FreeSurface(_tiles[i]);
	}

	//now delete the vector for good measure
	_tiles.clear();
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

	int total, temp, loop, x, y, pos; //pos is for array size, pushing to last element
	
	MapTile empty; //for push_back() prior to changes

	Input >> this->_width;
	Input >> this->_height; //read in w/h first, then onto each element

	total = ((_width / TILE_WIDTH) * (_height / TILE_HEIGHT));
	cout << "Map: Total tiles: " << total << endl;

	for (int i = 1; i <= total; i++)
	{
		this->_map.push_back(empty);
		pos = (int)this->_map.size() - 1;
		
		Input >> this->_map[pos].Anim;

		Input >> this->_map[pos].coords["x"];
		x =  this->_map[pos].coords["x"];

		Input >> this->_map[pos].coords["y"];
		y = this->_map[pos].coords["y"];
		
		//now read in the tiles for anim
		for (loop = 0; loop <= this->_map[pos].Anim; loop++)
		{
			Input >> temp;
			this->_map[pos].Tiles.push_back(temp);
		}

		//Input exit; >0 = exit number; 0 = not an exit
		Input >> this->_map[pos].Exit;

	}
	Input.close();
}

void Map::LoadObj(string file)
{
	/* OBJ STRUCTURE
	# of Objects

	@PER OBJECT:
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

	int temp, loop, pos, total, x, y;
	MapObj empty; //for push_back()

	Input >> total;

	for (int i = 0; i < total; i++)
	{
		this->_obj.push_back(empty);
		pos = (int)this->_obj.size() - 1;

		Input >> this->_obj[pos].Anim;

		Input >> this->_obj[pos].coords["x"];
		Input >> this->_obj[pos].coords["y"];

		//load animation frames
		for (loop = 0; loop <= this->_obj[pos].Anim; loop++)
		{
			Input >> temp;
			this->_obj[pos].Frames.push_back(temp);
		}

		//is object collidable? 1 = true, 0 = false
		Input >> temp;
		this->_obj[pos].Collidable = (temp > 0 ? true : false);

		Input >> this->_obj[pos].Item;
		Input >> this->_obj[pos].Interactive;
		Input >> this->_obj[pos].Door;

		//is object hidden? 1 = true, 0 = false
		Input >> temp;
		this->_obj[pos].Hidden = (temp > 0 ? true : false);
	}

	Input.close();
}

void Map::LoadTiles(string file)
{
	ifstream Input;
	Input.open(file.c_str());
	string temp;

	SDL_Surface* tempsdl;
	int amount;

	Input >> amount;

	for (int i = 1; i <= amount;i++)
	{
		Input >> temp;

		tempsdl = IMG_Load(temp.c_str());
		this->_tiles.push_back(tempsdl);

		cout << "Tile: " << temp << " loaded." << endl;

	}

	Input.close();
}

bool Map::IsCollidable(int x, int y)
{
	for (int i = 0; i < this->_obj.size(); i++)
	{
		if ((this->_obj[i].coords["x"] == x) && (this->_obj[i].coords["y"] == y))
		{
			cout << "Collision." << endl;
			return this->_obj[i].Collidable;
		}
	} 
}

void Map::SetPlayer(int x, int y, Player* player)
{
	_players[x][y] = player;
}

void Map::MovePlayer(int x, int y, Player* player)
{
	if ((x < 0) || (y < 0) || (x > this->_width) || (y > this->_height))
	{
		//TODO: throw error code here; outside out map boundary
	}

	Coords coords = player->GetPosition();
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

vector<MapTile> Map::GetMapTile()
{
	return this->_map;
}

vector<MapObj> Map::GetMapObj()
{
	return this->_obj;
}

vector<SDL_Surface*> Map::GetSDLTiles()
{
	return this->_tiles;
}
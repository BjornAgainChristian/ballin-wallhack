#include "Screen.h"

Screen::Screen(SDL_Surface *screen, Map map, Player mainPlayer)
{
	_screen = screen;
	_temp = IMG_Load("data/tiles/29.png"); //TODO remove after static test

	_map = &map;
	_mainPlayer = &mainPlayer;

	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER|SDL_HWSURFACE|SDL_DOUBLEBUF) < 0)
	{
		cerr << "Unable to init SDL: " << SDL_GetError() << endl;
	}

	TestLoop();
}

Screen::~Screen()
{
	SDL_FreeSurface(_screen);
	SDL_Quit();
}

void Screen::DrawIMG(SDL_Surface *img, int x, int y)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	
	SDL_BlitSurface(img, NULL, _screen, &dest);
}

void Screen::DrawIMG(SDL_Surface *img, int x, int y, int width, int height, int x2, int y2)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_Rect dest2;
	dest2.x = x2;
	dest2.y = y2;
	dest2.w = width;
	dest2.h = height;

	SDL_BlitSurface(img, &dest2, _screen, &dest);
}

void Screen::DrawBackground()
{
	//Fill the background solid black
	SDL_FillRect(_screen, NULL, 0xFFFFFF);
}

void Screen::DrawMap()
{
	Coords PlayerPos = _mainPlayer->GetPosition();
	vector<MapTile> tiles = _map->GetMapTile();
	vector<MapObj> objects = _map->GetMapObj(); //import tiles and objects from _map

	int x_start, y_start, x_trim, y_trim;
	x_trim = y_trim = 0; //start with no offsets, set later
	SDL_Surface *render; //render target
	vector<SDL_Surface*> tiles_render = _map->GetSDLTiles();

	//for rendering tiles to the left and top of where the player is located
	//the +1 /2 on these ensures tiles are rendered 1 past the boarders for clipped tiles
	x_start = PlayerPos["x"] - ((SCREEN_HARDCODE_WIDTH / 2) - TILE_WIDTH);
	if (x_start < 0)
	{
		x_start = 0;
	}
	else if (x_start + SCREEN_HARDCODE_WIDTH > _map->GetWidth())
	{
		x_start -= (x_start + SCREEN_HARDCODE_WIDTH - _map->GetWidth());
	}

	y_start = PlayerPos["y"] - ((SCREEN_HARDCODE_HEIGHT / 2) - TILE_HEIGHT);
	if (y_start < 0)
	{
		y_start = 0;
	}
	else if (y_start + SCREEN_HARDCODE_HEIGHT > _map->GetHeight())
	{
		y_start -= (y_start + SCREEN_HARDCODE_HEIGHT - _map->GetHeight());
	}

	//trimming player location to draw tiles in correct offset
	if (PlayerPos["x"] > SCREEN_HARDCODE_WIDTH)
	{
		x_trim = PlayerPos["x"] - SCREEN_HARDCODE_WIDTH;
	}
	if (PlayerPos["y"] > SCREEN_HARDCODE_HEIGHT)
	{
		y_trim = PlayerPos["y"] - SCREEN_HARDCODE_HEIGHT;
	}
	
	//loop through tiles and find the ones matching the coords x/y and render
	for (int i; i < tiles.size(); i++)
	{
		if ((tiles[i].coords["x"] >= x_start) && (tiles[i].coords["x"] <= x_start + SCREEN_HARDCODE_WIDTH))
		{
			if ((tiles[i].coords["y"] >= y_start) && (tiles[i].coords["y"] <= y_start + SCREEN_HARDCODE_HEIGHT))
			{

			}
		}
	}
}

void Screen::DrawSprites()
{

}

void Screen::DrawScene()
{
	this->DrawBackground();
	this->DrawMap();
	this->DrawSprites();

	SDL_Flip(_screen);
}

void Screen::HandleKeys()
{
	Uint8* keys;
	keys = SDL_GetKeyState(NULL);
	Coords PlayerPos = _mainPlayer->GetPosition();
}

void Screen::TestLoop()
{
	DrawScene();
	SDL_Delay(1000);
}
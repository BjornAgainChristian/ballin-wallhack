#include "Screen.h"

Screen::Screen(SDL_Surface *screen, Map map, Player mainPlayer)
{
	_screen = screen;
	_temp = IMG_Load("data/tiles/29.png"); //TODO remove after static test

	_map = map;
	_mainPlayer = mainPlayer;
}

Screen::~Screen()
{

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
	Coords playerPosition = _mainPlayer->GetPosition();

	
}

void Screen:DrawSprites()
{

}

void Screen::DrawScene()
{
	this->DrawBackGround();
	this->DrawMap();
	this->DrawSprites();

	SDL_Flip(_screen);
}

void Screen::HandleKeys()
{
	Uint8* keys;
	keys = SDL_GetKeyState(NULL);
	Coords coords = _mainPlayer->GetPosition();
}

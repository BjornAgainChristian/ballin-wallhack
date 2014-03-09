#include <iostream>

#include "Globals.h"
#include "Screen.h"
#include "Map.h"
#include "Player.h"

int main(int argc, char *argv[])
{
	if (argc > 1) {
		
	}

	Player player("test");
	player.SetPosition(100, 100);

	cout << "Loading map" << endl;

	Map map("data/maps/Test");
	//Map map; //TESTING ONLY

	cout << "Map loaded" << endl;

	Screen* screen = new Screen(SDL_SetVideoMode(SCREEN_HARDCODE_WIDTH, 
									SCREEN_HARDCODE_HEIGHT, 
									SCREEN_HARDCODE_BPP, SDL_NOFRAME),
									map,
									player);


	while (true) {
		//test
	}
	return 0;
}

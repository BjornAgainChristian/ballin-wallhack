#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream Output;
	Output.open("Test.map");
	if (Output.is_open())
	{
		cout << "Opened map, writing" << endl;	
	}
	else { 
		cout << "Cannot open file." << endl;
		return 0;
	}

	Output << 50 * 32 << endl << 50 * 32 << endl; //width/height

	for (int h = 0; h < 50; h++)
	{
		for (int w = 0; w < 50; w++)
		{
			cout << "Writing: " << w << " " << h << endl;
			
			Output << 0 << endl; //no anim
			Output << w * 32 << endl << h * 32 << endl; //coord
			Output << 0 << endl; //only one item in .tile
			if (w == 1) { //left boundary, can't move left
				Output << 1 << endl << 1 << endl << 1 << endl << 0 << endl << 1 << endl; 
			}
			else if (w == 50) { //right boundary, can't move right
				Output << 1 << endl << 1 << endl << 1 << endl << 1 << endl << 0 << endl;
			}
			else if (h == 1) { //top boundary, can't move up
				Output << 1 << endl << 0 << endl << 1 << endl << 1 << endl << 1 << endl;
			}
			else if (h == 50) { //bottom boundary, can't move down
				Output << 1 << endl << 1 << endl << 0 << endl << 1 << endl << 1 << endl;
			}
			else {
				Output << 1 << endl << 1 << endl << 1 << endl << 1 << endl << 1 << endl; //walkable in all dir
			}
			Output << 0 << endl; //tile is not an exit
		}
	}

	Output.close();
	
	return 0;
}

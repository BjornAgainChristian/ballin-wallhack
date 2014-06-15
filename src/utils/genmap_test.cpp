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
			Output << 0 << endl; //no anim
			Output << w * 32 << endl << h * 32 << endl; //coord

			if ((w * 32 == 768) && (h * 32 == 64))
			{
				Output << 1 << endl;
			}
			else if ((w * 32 == 800) && (h * 32 == 64))
			{
				Output << 2 << endl;
			}
			else if ((w * 32 == 832) && (h * 32 == 64))
			{
				Output << 3 << endl;
			}
			else if ((w * 32 == 768) && (h * 32 == 96))
			{
				Output << 4 << endl;
			}
			else if ((w * 32 == 800) && (h * 32 == 96))
			{
				Output << 5 << endl;
			}
			else if ((w * 32 == 832) && (h * 32 == 96))
			{
				Output << 6 << endl;
			}
			else if ((w * 32 == 768) && (h * 32 == 128))
			{
				Output << 7 << endl;
			}
			else if ((w * 32 == 800) && (h * 32 == 128))
			{
				Output << 8 << endl;
			}
			else if ((w * 32 == 832) && (h * 32 == 128))
			{
				Output << 9 << endl;
			}
			else {
				Output << 0 << endl; //default grass			
			}
			Output << 0 << endl; //tile is not an exit
		}
	}

	Output.close();
	
	return 0;
}

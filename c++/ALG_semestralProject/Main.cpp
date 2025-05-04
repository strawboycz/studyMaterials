#include<iostream>
#include "Maze.h"
/// <summary>
/// Vytvo�� bludi�t� podle parametr� zadan�ch do p��kazov�ho ��dku
/// </summary>
/// <param name="argc">po�et argument� p��kazov�ho ��dku</param>
/// <param name="argv">jednotliv� argumenty p��kazov�ho ��dku</param>
/// <returns>0 pokud v�e prob�hlo spr�vn�, 1 pokud nastala chyba p�i zad�n� parametr�</returns>
int main(int argc, char* argv[])
{
	int rows;
	int cols;
	unsigned int *seed = nullptr;
	if (argc >= 3) {
		rows = stoi(argv[1]);
		cols = stoi(argv[2]);
		if (argc == 4)
		{
			seed = new unsigned int(stoi(argv[3]));
		}
	}
	else
	{
		cout << "Invalid parameters!" << endl;
		return 1;
	}
	cout << "Generating maze..." << endl;
	Maze *maze = new Maze(rows,cols);
	maze->generatePath(seed);

	maze->saveSVG("maze.svg");

	cout << "Maze generated!" << endl;
	delete seed;
	return 0;
}

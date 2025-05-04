#include<iostream>
#include "Maze.h"
/// <summary>
/// Vytvoøí bludištì podle parametrù zadaných do pøíkazového øádku
/// </summary>
/// <param name="argc">poèet argumentù pøíkazového øádku</param>
/// <param name="argv">jednotlivé argumenty pøíkazového øádku</param>
/// <returns>0 pokud vše probìhlo správnì, 1 pokud nastala chyba pøi zadání parametrù</returns>
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

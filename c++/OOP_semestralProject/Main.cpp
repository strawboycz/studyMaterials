#include<iostream>
#include "Maze.h"
int main(int argc, char* argv[])
{
	int rows = 50;
	int cols = 50;
	Maze *maze = new Maze(rows,cols);
	maze->generatePath(time(NULL));

	maze->saveSVG("maze.svg");
	return 0;
}

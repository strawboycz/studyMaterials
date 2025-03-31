#include<iostream>
#include "Maze.h"
int main(int argc, char* argv[])
{
	int rows = 5;
	int cols = 5;
	Maze maze = Maze(rows,cols);
	maze.generatePath(time(NULL));

	maze.saveSVG("maze.svg");
	return 0;
}

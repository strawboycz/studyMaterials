#pragma once
#include <sstream>
#include <vector>
#include <xstring>
using namespace std;
class Maze
{
public:
	Maze();
	Maze(int rows, int cols);
private:
	int rows;
	int cols;
	class Cell
	{
	public:
		int id;
		bool leftWall = true;
		bool topWall = true;
		bool rightWall = true;
		bool bottomWall = true;
		int state = 2;
		vector<Cell*> neighbours;
		Cell(int id, vector<Cell*> neighbours): id(id), neighbours(neighbours)
		{
		}
		Cell(int id): id(id)
		{
		}
		string getSVG(int row, int col)
		{
			ostringstream ss;
			int x = col * 20;
			int y = row * 20;
			if(leftWall) ss << "<line x1=\"" << x << "\" y1=\"" << y << "\" x2=\"" << (x + 20) << "\" y2=\"" << y << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			if(rightWall) ss << "<line x1=\"" << (x + 20) << "\" y1=\"" << y << "\" x2=\"" << (x + 20) << "\" y2=\"" << (y + 20) << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			if(bottomWall) ss << "<line x1=\"" << (x + 20) << "\" y1=\"" << (y + 20) << "\" x2=\"" << x << "\" y2=\"" << (y + 20) << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			if(topWall) ss << "<line x1=\"" << x << "\" y1=\"" << (y + 20) << "\" x2=\"" << x << "\" y2=\"" << y << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			return ss.str();
		}
	};
	vector<Cell*> cells;
	Cell* findCell(int id);
	void fillUp();
public:
	void insert(int cellId);
	void insert(int cellId, vector<int> neighbourIds);
	void saveSVG(string path);
	void generatePath(unsigned int seed);
};

#pragma once
#include <vector>
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
		vector<Cell*> neighbours;
		Cell(int id, const vector<Cell*>& neighbours): id(id), neighbours(neighbours)
		{
		}
		Cell(int id): id(id)
		{
		}
	};
	vector<Cell*> cells;
	Maze::Cell* findCell(int id);
public:
	void insert(int cellId);
	void insert(int cellId, vector<int> neighbourIds);
	void fillUp();
};

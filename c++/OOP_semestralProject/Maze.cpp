#include "Maze.h"
#include <vector>
using namespace std;
Maze::Maze()
{
}

Maze::Maze(int rows, int cols) : rows(rows), cols(cols)
{
}
void Maze::insert(int cellId)
{
	this->cells.push_back(new Cell(cellId));
}

Maze::Cell* Maze::findCell(int id)
{
	for (auto cell : this->cells)
	{
		if (cell->id == id)
		{
			return cell;
		}
	}
	return nullptr;
}
void Maze::insert(int cellId, vector<int> neighbourIds)
{
	this->cells.push_back(new Cell(cellId));
	for (auto neighbourId : neighbourIds)
	{
		this->findCell(neighbourId)->neighbours.push_back(this->findCell(cellId));
		if (cellId != neighbourId)
		{
			this->findCell(cellId)->neighbours.push_back(this->findCell(neighbourId));
		}
	}
}
void Maze::fillUp()
{
	for (int i = 0; i < cols; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{

		}
	}
}

#include "Maze.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void Maze::fillUp()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			this->insert(cols * i + j);
		}
	}


	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			Cell* curent = this->findCell(cols * i + j);
			if (i > 0)
			{
				curent->neighbours.push_back(this->findCell(cols * (i - 1) + j));
			}
			if (j > 0)
			{
				curent->neighbours.push_back(this->findCell(cols * i + j - 1));
			}
			if (j < cols - 1)
			{
				curent->neighbours.push_back(this->findCell(cols * i + j + 1));
			}
			if (i < rows - 1)
			{
				curent->neighbours.push_back(this->findCell(cols * (i + 1) + j));
			}
		}
	}
}
Maze::Maze()
{
	this->rows = 1;
	this->cols = 1;
	this->fillUp();
}

Maze::Maze(int rows, int cols) : rows(rows), cols(cols)
{
	this->fillUp();
}
void Maze::insert(int cellId)
{
	if (this->findCell(cellId)) return;
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
	if (this->findCell(cellId)) return;
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
void Maze::saveSVG(string path)
{
	ofstream file(path);
	file << "<svg width=\"" << this->cols * 20 << "\" height=\"" << this->rows * 20 << "130\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			file << this->findCell(cols * i + j)->getSVG(i,j);
		}
	}
	file << "</svg>" << endl;
	file.close();
}
void Maze::generatePath(unsigned int seed)
{
	srand(seed);
	int currentIndex = rand() % cols;
	this->findCell(currentIndex)->topWall = false;
	int endIndex = rand() % ((rows * cols - 1) - (rows * (cols - 1)) + 1) + rows*(cols - 1);
	this->findCell(currentIndex)->bottomWall = false;

	/*while (currentIndex != endIndex)
	{
		
	}*/
}


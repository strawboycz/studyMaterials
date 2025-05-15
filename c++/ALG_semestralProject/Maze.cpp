#include "Maze.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
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
			else curent->neighbours.push_back(nullptr);
			if (j > 0)
			{
				curent->neighbours.push_back(this->findCell(cols * i + j - 1)); 
			}
			else curent->neighbours.push_back(nullptr);
			if (j < cols - 1)
			{
				curent->neighbours.push_back(this->findCell(cols * i + j + 1)); 
			}
			else curent->neighbours.push_back(nullptr);
			if (i < rows - 1)
			{
				curent->neighbours.push_back(this->findCell(cols * (i + 1) + j)); 
			}
			else curent->neighbours.push_back(nullptr);

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

Maze::~Maze()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			delete cells[cols * i + j];
		}
	}
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
	file << "<svg width=\"" << this->cols * 20 << "\" height=\"" << this->rows * 20 << "\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
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
int Maze::size()
{
	return this->cols * this->rows;
}

vector<Maze::Cell*> Maze::getShuffeledNeighbours(vector<Cell*> neighbours)
{
	vector<Cell*> copy = neighbours;
	for (int i = copy.size() - 1; i > 0; i--)
	{
		int j = rand() % (i+ 1);
		swap(copy[j], copy[i]);
	}
	

	return copy;
}
void Maze::generatePath(unsigned int *seed)
{
	if (seed)
	{
		srand(*seed);
	}
	int startIndex = rand() % cols;

	stack<Cell*> stack;
	vector<bool> visited(this->size(),false);
	Cell* start = findCell(startIndex);
	start->topWall = false;
	visited[start->id] = true;
	stack.push(start);


	while (!stack.empty())
	{
		Cell* current = stack.top();
		stack.pop();

		vector<Cell*> neighbours = this->getShuffeledNeighbours(current->neighbours);
		
			for (auto neighbour :neighbours)
			{

				if (neighbour && !visited[neighbour->id])
				{

					visited[neighbour->id] = true;

					if (current->neighbours[0] == neighbour) //if its top neighbour
					{
						current->topWall = false;
						neighbour->bottomWall = false;
					}
					if (current->neighbours[1] == neighbour) //if its left neighbour
					{
						current->leftWall = false;
						neighbour->rightWall = false;
					}
					if (current->neighbours[2] == neighbour) //if its right neighbour
					{
						current->rightWall = false;
						neighbour->leftWall = false;
					}
					if (current->neighbours[3] == neighbour) //if its bottom neighbour
					{
						current->bottomWall = false;
						neighbour->topWall = false;
					}
					stack.push(current);
					stack.push(neighbour);
					break;
				}
			
			}
			
	}
	int endIndex = rand() % ((rows * cols - 1) - (rows * (cols - 1)) + 1) + rows * (cols - 1);

	this->findCell(endIndex)->bottomWall = false;

}


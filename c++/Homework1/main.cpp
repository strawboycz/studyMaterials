#include <iostream>
#include <sstream>

#include "Homework1/Node.h"
using namespace std;


int main(int argc, char* argv[])
{
	double values[] = { 1,-6,59,103,114,5,58};
	Node<double> treeTop = Node<double>(100);
	for (auto value : values)
	{
		treeTop.createNext(value);
	}
	cout << treeTop.toString();
}

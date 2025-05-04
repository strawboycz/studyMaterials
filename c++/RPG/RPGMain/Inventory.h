#pragma once
#include <vector>

#include "Item.h"
using namespace std;
class Inventory
{
public:
	Inventory();
	void addItem(Item *item);
	void removeItem(string name);
	void clearItems();
	void printAllItems();
private:
	vector<Item*> items;
};

#include "Inventory.h"

#include <iostream>

Inventory::Inventory()
{
	
}
void Inventory::addItem(Item* item)
{
	this->items.push_back(item);
}
void Inventory::removeItem(string name)
{
	for (auto it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->getName() == name)
		{
			delete* it;
			items.erase(it);
			break;
		}
	}
}
void Inventory::clearItems()
{
	this->items.clear();
}
void Inventory::printAllItems()
{
	cout << "Items in inventory: " << endl;
	for (auto item : items)
	{
		cout << item->toString() << endl;
	}
}

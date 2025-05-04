#include "Building.h"
Building::Building(string name, string number) : name(name), number(number)
{
	
}

string Building::getName()
{
	return name;
}

void Building::setName(string name)
{
	this->name = name;
}

string Building::getNumber()
{
	return number;
}

void Building::setNumber(string number)
{
	this->number = number;
}

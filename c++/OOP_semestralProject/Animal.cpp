#include "Animal.h"

#include <iostream>

Animal::Animal(string name)
{
	this->name = name;
}
string Animal::getName()
{
	return name;
}
void Animal::setName(string name)
{
	this->name = name;
}

int Animal::getId() 
{
	return id;
}

void Animal::setId(int id)
{
	this->id = id;
}

string Animal::getSpecies() 
{
	return species;
}

void Animal::setSpecies(string species)
{
	this->species = species;
}

Sex Animal::getSex() 
{
	return sex;
}

void Animal::setSex(Sex sex)
{
	this->sex = sex;
}

string Animal::toString() {
	cout << "Animal Information:" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Species: " << species << endl;
	cout << "Sex: " << (sex == male) ? "male" : ((sex==female) ? "female" : "unspecified") << endl;
}


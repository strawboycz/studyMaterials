#include "Animal.h"

#include <iostream>

Animal::Animal(int id, string name, string species, Sex sex, Building* keptAt) : id(id), name(name), species(species), sex(sex), keptAt(keptAt)
{

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
	string outp;
	outp += "Animal Information:\n";
	outp += "ID: " + std::to_string(id) + "\n";
	outp += "Name: " + name + "\n";
	outp += "Species: " + species + "\n";
	std::string sexStr = (sex == male) ? "male" :
		(sex == female) ? "female" :
		"unspecified";

	outp += "Sex: " + sexStr + "\n";
	return outp;
}

Building* Animal::getKeptAt()
{
	return this->keptAt;
}

void Animal::setKeptAt(Building *& building)
{
	this->keptAt = building;
}
Animal::~Animal()
{
	delete this->keptAt;
}

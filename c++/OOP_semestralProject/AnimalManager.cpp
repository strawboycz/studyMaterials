#include "AnimalManager.h"

#include <iostream>

vector<Animal*>& AnimalManager::getAnimals()
{
	return animals;
}

void AnimalManager::setAnimals(vector<Animal*>& newAnimals)
{
	animals = newAnimals;
}
void AnimalManager::addAnimal(Animal* animal)
{
	animals.push_back(animal);
}
void AnimalManager::addAnimal(int id, string name,Sex sex ,string species, Building* habitat)
{
	animals.push_back(new Animal(id,name,species,sex,habitat));
}

void AnimalManager::printAnimals()
{
	for (auto animal : animals)
	{
		cout << animal->toString() << endl;
	}
}

Animal* AnimalManager::getAnimal(int id)
{
	for (auto animal : animals)
	{
		if (animal->getId() == id) return animal;
	}
}

vector<Animal*> AnimalManager::getAnimals(string name)
{
	vector<Animal*> outp;
	for (auto animal : animals)
	{
		if (animal->getName() == name) outp.push_back(animal);
	}
	return outp;
}
vector<Animal*> AnimalManager::getAnimals(Habitat* habitat)
{
	vector<Animal*> outp;
	for (auto animal : animals)
	{
		if (animal->getKeptAt() == habitat) outp.push_back(animal);
	}
	return outp;
}
void AnimalManager::cleanup() {
	for (auto animal : this->animals) {
		delete animal;
	}
	this->animals.clear();
}

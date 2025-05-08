#include "AnimalManager.h"

#include <iostream>

int AnimalManager::getAnimalCount()
{
	return animalCount;
}

void AnimalManager::setAnimalCount(int animalCount)
{
	this->animalCount = animalCount;
}

vector<Animal*>& AnimalManager::getAnimals()
{
	return this->animals;
}

void AnimalManager::setAnimals(vector<Animal*>& animals)
{
	this->animals = animals;
}
void AnimalManager::addAnimal(Animal* animal)
{
	this->animalCount++;
	this->animals.push_back(animal);
}
void AnimalManager::printAnimals()
{
	for (auto animal : this->animals)
	{
		cout << animal->toString() << endl;
	}
}

Animal* AnimalManager::getAnimal(int id)
{
	for (auto animal : this->animals)
	{
		if (animal->getId() == id) return animal;
	}
}

vector<Animal*> AnimalManager::getAnimals(string name)
{
	vector<Animal*> outp;
	for (auto animal : this->animals)
	{
		if (animal->getName() == name) outp.push_back(animal);
	}
	return outp;
}
vector<Animal*> AnimalManager::getAnimals(Habitat* habitat)
{
	vector<Animal*> outp;
	for (auto animal : this->animals)
	{
		if (animal->getKeptAt() == habitat) outp.push_back(animal);
	}
	return outp;
}

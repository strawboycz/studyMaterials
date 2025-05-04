#include "AnimalManager.h"

int AnimalManager::getCurrentId()
{
	return currentId;
}

void AnimalManager::setCurrentId(int current_id)
{
	currentId = current_id;
}

vector<Animal*> AnimalManager::getAnimals()
{
	return animals;
}

void AnimalManager::setAnimals(const vector<Animal*>& animals)
{
	this->animals = animals;
}
void AnimalManager::addAnimal(Animal* animal)
{
	this->animals.push_back(animal);
}

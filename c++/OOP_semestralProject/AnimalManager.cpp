#include "AnimalManager.h"

int AnimalManager::getAnimalCount()
{
	return animalCount;
}

void AnimalManager::setAnimalCount(int animalCount)
{
	this->animalCount = animalCount;
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
	this->animalCount++;
	this->animals.push_back(animal);
}

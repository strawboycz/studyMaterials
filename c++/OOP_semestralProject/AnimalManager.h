#pragma once
#include <vector>

#include "Animal.h"
using namespace std;
static class AnimalManager
{
public:
	AnimalManager() = default;
	~AnimalManager() = default;
	int getAnimalCount();
	void setAnimalCount(int animalCount);
	vector<Animal*> getAnimals();
	void setAnimals(const vector<Animal*>& animals);
	void addAnimal(Animal* animal);
private:
	int animalCount = 0;
	vector<Animal*> animals;

};

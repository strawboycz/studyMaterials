#pragma once
#include <vector>

#include "Animal.h"
using namespace std;
/// <summary>
/// Třída pro správu konkrétních zvířat v systému
/// </summary>
static class AnimalManager
{
public:
	AnimalManager() = default;
	~AnimalManager() = default;
	int getAnimalCount();
	void setAnimalCount(int animalCount);
	vector<Animal*> getAnimals();
	void setAnimals(vector<Animal*>& animals);
	void addAnimal(Animal* animal);
	void printAnimals();
private:
	int animalCount = 0;
	vector<Animal*> animals;

};

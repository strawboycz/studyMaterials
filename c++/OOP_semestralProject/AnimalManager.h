#pragma once
#include <vector>

#include "Animal.h"
using namespace std;
static class AnimalManager
{
public:
	AnimalManager() = default;
	~AnimalManager() = default;
	int getCurrentId();
	void setCurrentId(int current_id);
	vector<Animal*> getAnimals();
	void setAnimals(const vector<Animal*>& animals);
	void addAnimal(Animal* animal);
private:
	int currentId = 0;
	vector<Animal*> animals;

};

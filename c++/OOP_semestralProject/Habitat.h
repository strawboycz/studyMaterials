#pragma once
#include "Building.h"

class Habitat : public Building
{
public:
	string toString() override;
	int getAnimalCapacity();
	void setAnimalCapacity(int animal_capacity);

private:
	int animalCapacity;
};

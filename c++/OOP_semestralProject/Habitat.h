#pragma once
#include "Building.h"

class Habitat : public Building
{
public:
	Habitat(string name,string number, int animalCapacity);
	string toString() override;
	int getAnimalCapacity();
	void setAnimalCapacity(int animal_capacity);

private:
	int animalCapacity;
};

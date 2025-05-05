#pragma once
#include "Building.h"
/// <summary>
/// Třída představující výběh 
/// </summary>
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

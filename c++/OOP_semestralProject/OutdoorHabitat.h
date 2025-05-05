#pragma once
#include "Habitat.h"

class OutdoorHabitat : public Habitat
{
public:
	OutdoorHabitat(string name, string number,int animalCapacity, string biome);
	string toString() override;
	string getBiome();
	void setBiome(string biome);

private:
	string biome;
};

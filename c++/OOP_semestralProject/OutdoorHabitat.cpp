#include "OutdoorHabitat.h"

string OutdoorHabitat::getBiome()
{
	return biome;
}

void OutdoorHabitat::setBiome(string biome)
{
	this->biome = biome;
}
OutdoorHabitat::OutdoorHabitat(string name, string number,int animalCapacity, string biome) : Habitat(name,number,animalCapacity), biome(biome)
{
	
}

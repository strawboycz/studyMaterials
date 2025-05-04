#include "Habitat.h"

int Habitat::getAnimalCapacity()
{
	return animalCapacity;
}

void Habitat::setAnimalCapacity(int animal_capacity)
{
	animalCapacity = animal_capacity;
}
string Habitat::toString()
{
	return "Habitat " + this->name + " " + this->number;
}

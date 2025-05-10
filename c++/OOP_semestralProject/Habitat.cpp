#include "Habitat.h"
Habitat::~Habitat()
{
	
}

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
Habitat::Habitat(string name, string number, int animalCapacity) : Building(name, number), animalCapacity(animalCapacity)
{
	
}

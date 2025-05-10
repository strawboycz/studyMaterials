#include <iostream>

#include "AnimalManager.h"
#include "IdManager.h"
#include "OutdoorHabitat.h"
#include "Zookeeper.h"
#include "IdManager.h"


int main()
{
	// Habitats
	Habitat* habitats[4];
	habitats[0] = new Habitat("African savanna", "B-102", 15);
	habitats[1] = new Habitat("Tropical jungle", "A-210", 10);
	habitats[2] = new OutdoorHabitat("Lions den", "C-305", 20, "savanna");
	habitats[3] = new OutdoorHabitat("Polar zone", "D-403", 8, "arctic");

	// Animals
	AnimalManager* am = new AnimalManager();
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Simba", "Panthera leo", male, habitats[2]));
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Nala", "Panthera leo", female, habitats[2]));

	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Kiki", "Gorilla gorilla", female, habitats[1]));
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Bongo", "Gorilla gorilla", male, habitats[1]));

	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Arktos", "Ursus maritimus", male, habitats[3]));
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Lumi", "Ursus maritimus", female, habitats[3]));

	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Rafiki", "Mandrillus sphinx", male, habitats[1]));
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Zazu", "Genus Aotus", male, habitats[1]));
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Tala", "Genus Aotus", female, habitats[1]));
	am->addAnimal(new Animal(IdManager::generateAnimalId(), "Moyo", "Mandrillus sphinx", female, habitats[1]));


	// Zookeepers
	Zookeeper* zookeepers[5];
	zookeepers[0] = new Zookeeper("Petr", "Novak", IdManager::generateZooKeeperId(), 58000);
	zookeepers[1] = new Zookeeper("Jana", "Kralova", IdManager::generateZooKeeperId(), 61000);
	zookeepers[2] = new Zookeeper("Lukas", "Dvorak", IdManager::generateZooKeeperId(), 57000);
	zookeepers[3] = new Zookeeper("Eva", "Svobodova", IdManager::generateZooKeeperId(), 59000);
	zookeepers[4] = new Zookeeper("Tomas", "Blaha", IdManager::generateZooKeeperId(), 60500);



	for (auto animal : am->getAnimals())
	{
		cout << animal->toString() << "Lives in: ";
		cout << animal->getKeptAt()->toString() << endl << endl;
	}
	am->cleanup();
	delete am;
	for (int i = 0; i < 5; ++i) delete zookeepers[i];
	for (int i = 0; i < 4; ++i) delete habitats[i];
	return 0;
}
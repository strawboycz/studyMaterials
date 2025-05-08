#include <iostream>

#include "AnimalManager.h"
#include "OutdoorHabitat.h"
#include "Zookeeper.h"
/*
 *Bude obsahovat alespoò 7 rozdílných tøíd.Tøídy budou obsahovat vlastní atributy,
konstruktory a destruktor této tøídy.

• Alespoò jednou bude v projektu implementováno dynamické pole objektù jiné tøídy.
• Alespoò u jedné tøídy bude pøetížená metoda.
• V hlavní èásti bude vytvoøení a použití nìkolika instancí a volání metod.
• U každé tøídy je vhodné také do poznámky v kódu krátce popsat, co tøída reprezentuje.
*/
int main()
{
	AnimalManager* am = new AnimalManager();

	// Habitats
	Habitat* savana = new Habitat("African savanna", "B-102", 15);
	Habitat* tropicalForest = new Habitat("Tropical jungle", "A-210", 10);
	OutdoorHabitat* lionHabitat = new OutdoorHabitat("Lions den", "C-305", 20, "savanna");
	OutdoorHabitat* arcticZone = new OutdoorHabitat("Polar zone", "D-403", 8, "arctic");

	// Animals
	am->addAnimal(new Animal(1, "Simba", "Panthera leo", male, lionHabitat));
	am->addAnimal(new Animal(2, "Nala", "Panthera leo", female, lionHabitat));

	am->addAnimal(new Animal(3, "Kiki", "Gorilla gorilla", female, tropicalForest));
	am->addAnimal(new Animal(4, "Bongo", "Gorilla gorilla", male, tropicalForest));

	am->addAnimal(new Animal(5, "Arktos", "Ursus maritimus", male, arcticZone));
	am->addAnimal(new Animal(6, "Lumi", "Ursus maritimus", female, arcticZone));

	am->addAnimal(new Animal(7, "Rafiki", "Mandrillus sphinx", male, tropicalForest));
	am->addAnimal(new Animal(8, "Zazu", "Genus Aotus", male, tropicalForest));
	am->addAnimal(new Animal(9, "Tala", "Genus Aotus", female, tropicalForest));
	am->addAnimal(new Animal(10, "Moyo", "Mandrillus sphinx", female, tropicalForest));


	// Zookeepers
	Zookeeper* zookeepers = new Zookeeper[5];
	zookeepers[0] = Zookeeper("Petr", "Novak", 1, 58000);
	zookeepers[1] = Zookeeper("Jana", "Kralova", 2, 61000);
	zookeepers[2] = Zookeeper("Lukas", "Dvorak", 3, 57000);
	zookeepers[3] = Zookeeper("Eva", "Svobodova", 4, 59000);
	zookeepers[4] = Zookeeper("Tomas", "Blaha", 5, 60500);



	for (auto animal : am->getAnimals())
	{
		cout << animal->toString() << "Lives in: ";
		cout << animal->getKeptAt()->toString() << endl << endl;
	}
	delete[] zookeepers;

	return 0;
}
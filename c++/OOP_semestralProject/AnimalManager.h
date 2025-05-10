#pragma once
#include <vector>

#include "Animal.h"
#include "Habitat.h"
using namespace std;
/// <summary>
/// Třída pro správu konkrétních zvířat v systému
/// </summary>
class AnimalManager {
public:
  AnimalManager() = default;
  ~AnimalManager() = default;

  vector<Animal*>& getAnimals();
  void setAnimals(vector<Animal*>& newAnimals);
  void addAnimal(Animal* animal);
  void addAnimal(int id, string name, Sex sex, string species, Building* habitat);
  void printAnimals();
	Animal* getAnimal(int id);
  vector<Animal*> getAnimals(string name);
	vector<Animal*> getAnimals(Habitat* habitat);
  void cleanup();
private:
   vector<Animal*> animals;
};

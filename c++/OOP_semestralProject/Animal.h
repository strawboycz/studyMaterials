#pragma once
#include <string>

#include "Building.h"
#include "Sex.h"
using namespace std;
/// <summary>
/// Třída reprezentující konkrétní zvíře
/// </summary>
class Animal
{
public:
	Animal(int id, string name, string species, Sex sex, Building* keptAt);
	~Animal();
	string getName();
	void setName(string name);
	int getId();
	void setId(int id);
	string getSpecies();
	void setSpecies(string species);
	Sex getSex();
	void setSex(Sex sex);
	string toString();
	Building* getKeptAt();
	void setKeptAt(Building*& building);
private:
	int id;
	Building* keptAt;
	string name;
	string species;
	Sex sex;
};

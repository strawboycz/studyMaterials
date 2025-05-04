#pragma once
#include <string>
#include "Sex.h"
using namespace std;
class Animal
{
public:
	Animal(string name);
	string getName();
	void setName(string name);
	int getId();
	void setId(int id);
	string getSpecies();
	void setSpecies(string species);
	Sex getSex();
	void setSex(Sex sex);
protected:
	int id;
	string name;
	string species;
	Sex sex;
};

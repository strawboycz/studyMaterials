#pragma once
#include <string>
#include "Sex.h"
using namespace std;
/// <summary>
/// Třída reprezentující konkrétní zvíře
/// </summary>
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
	string toString();

protected:
	int id;
	string name;
	string species;
	Sex sex;
};

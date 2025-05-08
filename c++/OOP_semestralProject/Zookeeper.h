#pragma once
#include <string>
#include <vector>

#include "Habitat.h"
#include "Person.h"
using namespace std;
class Zookeeper : public Person
{
public:
	Zookeeper();
	Zookeeper(string firstname, string lastname, int badgeNumber, double salary);
	~Zookeeper();
	int getBadgeNumber();
	double getSalary();
	void setSalary(double newSalary);
	vector<Habitat*> getTendingTo();
	void addHabitat(Habitat* habitat);
	void removeHabitat(string number);
private:
	int badgeNumber;
	double salary;
	vector<Habitat*> tendingTo;
};

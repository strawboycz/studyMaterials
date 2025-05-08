#include "Zookeeper.h"
Zookeeper::Zookeeper(string firstname, string lastname, int badgeNumber, double salary) : Person(firstname,lastname), badgeNumber(badgeNumber), salary(salary)
{
	
}
Zookeeper::Zookeeper() : Person("","")
{
	this->badgeNumber = -1;
	this->salary = 0;
}
Zookeeper::~Zookeeper()
{
	
}

int Zookeeper::getBadgeNumber()
{
	return this->badgeNumber;
}
double Zookeeper::getSalary()
{
	return this->salary;
}
vector<Habitat*> Zookeeper::getTendingTo()
{
	return this->tendingTo;
}
void Zookeeper::setSalary(double newSalary)
{
	this->salary = newSalary;
}
void Zookeeper::addHabitat(Habitat* habitat)
{
	this->tendingTo.push_back(habitat);
}
void Zookeeper::removeHabitat(string number)
{
	for (auto it = this->tendingTo.begin(); it == this->tendingTo.end(); it++)
	{
		if ((*it)->getNumber() == number)
		{
			this->tendingTo.erase(it);
			break;
		}
	}
}
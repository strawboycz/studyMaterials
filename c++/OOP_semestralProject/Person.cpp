#include "Person.h"
Person::Person(string firstName, string lastName) : firstName(firstName), lastName(lastName)
{
	
}
string Person::getFirstName()
{
	return this->firstName;
}
string Person::getLastName()
{
	return this->lastName;
}

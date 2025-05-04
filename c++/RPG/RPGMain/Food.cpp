#include "Food.h"
Food::Food(string name, double healAmount) : Item(name), healAmount(healAmount)
{
	
}
string Food::toString()
{
	return this->name + " - heals for " + std::to_string(this->healAmount)+ " health";
}
double Food::getHealAmount()
{
	return this->healAmount;
}


#include "Weapon.h"
Weapon::Weapon(string name, double bonusDmg) : Item(name), bonusDmg(bonusDmg)
{
	
}
double Weapon::getBonusDmg()
{
	return this->bonusDmg;
}
string Weapon::toString()
{
	return this->name + " - deals additional " + std::to_string(this->bonusDmg) + " bonus damage";
}

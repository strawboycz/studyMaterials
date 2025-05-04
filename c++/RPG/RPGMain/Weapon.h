#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(string name, double bonusDmg);
	double getBonusDmg();
	string toString() override;

private:
	double bonusDmg;

};

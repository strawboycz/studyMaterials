#pragma once
#include "Sprite.h"

class Monster : public Sprite
{
protected:
	double chanceToDoge;
public:
	Monster(double hp, double baseDmg, double chanceToDoge);
	void heal(double amount);
	bool getHit(double dmg);
};


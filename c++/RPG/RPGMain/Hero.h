#pragma once
#include "Monster.h"
#include "Sprite.h"

class Hero : public Sprite
{
private:
	std::string name;
public:
	Hero(double hp, double baseDmg, std::string name);
	void shout(Hero* enemy);
	std::string getName();
	void shout(Monster* enemy);
	void getShoutedOn(Hero* other);
};


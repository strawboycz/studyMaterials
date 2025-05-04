#pragma once
#include "Food.h"
#include "Inventory.h"
#include "Monster.h"
#include "Sprite.h"
using namespace std;
class Hero : public Sprite
{
private:
	std::string name;
public:
	Inventory	inventory;
	Hero(double hp, double baseDmg, std::string name);
	void shout(Hero* enemy);
	std::string getName();
	void shout(Monster* enemy);
	void getShoutedOn(Hero* other);
	void eatFood(Food* other);
};


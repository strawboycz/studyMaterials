#include "Hero.h"

#include "Monster.h"

std::string Hero::getName()
{
	return this->name;
}
Hero::Hero(double hp, double baseDmg, std::string name) : Sprite(hp,baseDmg)
{
	this->name = name;
}
void Hero::shout(Monster* enemy)
{
	std::cout << "Hey monster, my name is " << this->name << "! And I'm going to fight you.\n";
}
void Hero::shout(Hero* enemy)
{
	std::cout << "Hey monster, my name is " << this->name << "! And I'm going to fight you.\n";
	enemy->getShoutedOn(this);
}
void Hero::getShoutedOn(Hero *other)
{
	std::cout << "Hey " << other->getName() << " I am not your enemy, please dont fight.\n";
}
void Hero::eatFood(Food* other)
{
	this->HP += other->getHealAmount();
}


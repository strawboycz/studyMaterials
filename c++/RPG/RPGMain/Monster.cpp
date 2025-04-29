#include "Monster.h"

#include <random>

void Monster::heal(double amount)
{
	if (this->isAlive())
	{
		this->HP += amount;
	}
}
Monster::Monster(double hp, double baseDmg, double chanceToDoge) : Sprite(hp, baseDmg)
{
	this->chanceToDoge = std::min(100.0,chanceToDoge);
}
bool Monster::getHit(double dmg)
{
	std::random_device random;
	std::mt19937 gen(random());
	std::uniform_int_distribution<> distrib(0, 100);
	if (this->chanceToDoge > distrib(gen))
	{
		return Sprite::getHit(dmg);
	}
	return true;
}


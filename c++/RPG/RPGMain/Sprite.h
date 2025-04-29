#pragma once
#include <iostream>

class Sprite
{
public:
	Sprite(double HP, double baseDmg);
	bool getHit(double dmg);
	void attack(Sprite* targetSprite);
	bool isAlive();
protected:
	double HP;
	double baseDamage;
};


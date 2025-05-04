#pragma once
#include "Item.h"

class Food : public Item
{
public:
	Food(string name, double healAmount);
	string toString() override;
	double getHealAmount();
private:
	double healAmount;
};

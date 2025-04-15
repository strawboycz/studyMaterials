#pragma once
#include "Electronics.h"

class PowerBank : Electronics
{
private:
	double width;
	double height;
	int capacity;
public:
	PowerBank(double width, double height, int capacity);

	void printParameters() override;
	double getWidth();
	double getHeight();
	int getCapacity();
};

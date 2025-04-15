#include "PowerBank.h"

#include <iostream>

using namespace std;

void PowerBank::printParameters()
{
	cout << "Powerbank with height: " << this->height  << "cm width: " << this->width << "cm capacity: " << this->capacity << "mAh" << endl;
}

double PowerBank::getWidth()
{
	return this->width;
}

double PowerBank::getHeight()
{
	return this->height;
}

int PowerBank::getCapacity()
{
	return this->capacity;
}

PowerBank::PowerBank(double width, double height, int capacity)
	: width(width),
	height(height),
	capacity(capacity)
{
}
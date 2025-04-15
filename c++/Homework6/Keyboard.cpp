#include "Keyboard.h"

#include <iostream>

void Keyboard::printParameters()
{
	cout << "Name: " << this->name << " Count of keys: " << this->keyCount << (this->numpad ? " Has numpad" : " Hasn't got a numpad") << endl;

}

string Keyboard::getName()
{
	return this->name;
}

int Keyboard::getKeyCount()
{
	return this->keyCount;
}

bool Keyboard::getNumpad()
{
	return this->numpad;
}
Keyboard::Keyboard(const string& name, int key_count, bool numpad)
	: name(name),
	keyCount(key_count),
	numpad(numpad)
{
}

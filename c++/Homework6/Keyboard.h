#pragma once
#include <string>

#include "Electronics.h"
using namespace std;
class Keyboard : Electronics
{
private:
	string name;
	int keyCount;
	bool numpad;

public:
	Keyboard(const string& name, int key_count, bool numpad);

	void printParameters() override;
	string getName();
	int getKeyCount();
	bool getNumpad();
};

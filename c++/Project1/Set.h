#pragma once
#include <string>

class Set
{
public:
	Set(int length);
	~Set();
	int getCount();
	int getAt(int i);
	bool push(int value);
	bool contains(int value);
	Set* getUnion(Set* secondSet);
	Set* getComplement(Set* secondSet);
	std::string toString();
private:
	int* array;
	int length;
	int count;
};

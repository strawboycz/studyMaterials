#pragma once
#include <string>

using namespace std;

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(unsigned int n);
	DynamicArray(int *arr,unsigned int length);
	~DynamicArray();
	int getAt(unsigned int index);
	void setAt(unsigned int index, int value);
	void add(int number);
	void removeAt(unsigned int index);
	string toString();
private:
	unsigned int counter;
	unsigned int length;
	int *data;

};

#pragma once
#include <string>

#include "Card.h"

using namespace std;

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(unsigned int n);
	DynamicArray(Card *arr,unsigned int length);
	~DynamicArray();
	Card getAt(unsigned int index);
	void setAt(unsigned int index, Card value);
	void add(Card card);
	void removeAt(unsigned int index);
	string toString();
	int size();
	void shuffle();
	Card* getData();
	Card* data;
private:
	unsigned int counter;
	unsigned int length;

};

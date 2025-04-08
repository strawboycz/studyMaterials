#pragma once
#include "CardStack.h"

class CardStackIterator
{
private:
	DynamicArray *cards;
	int currentIndex;
public:
	CardStackIterator(DynamicArray* data);
	bool hasNext();
	Card next();
};

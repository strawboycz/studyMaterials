#pragma once
#include <vector>

#include "Card.h"
#include "DynamicArray.h"
using namespace std;
class CardStack
{
public:
	DynamicArray cards;

	static CardStack* createSevenToAceDeck();
	CardStack() = default;
	void push(Card card);
	void pop();
	Card peek();
	void shuffle();
};

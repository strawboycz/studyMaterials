#include "CardStack.h"
#include <random>
#include <set>

void CardStack::push(Card card)
{
	this->cards.add(card);
}
void CardStack::pop()
{
	this->cards.removeAt(cards.size() - 1);
}
Card CardStack::peek()
{
	return this->cards.getAt(cards.size() - 1);
}
CardStack* CardStack::createSevenToAceDeck()
{
	CardStack* cs = new CardStack();
	for (int i = 7; i <= 13; i++)
	{
		for (int j = Card::CardSymbol::spades; j <= Card::CardSymbol::hearts; j++)
		{
			cs->push(Card(i, (Card::CardSymbol)j));
		}
	}
	for (int j = Card::CardSymbol::spades; j <= Card::CardSymbol::hearts; j++)
	{
		cs->push(Card(1, (Card::CardSymbol)j));
	}
	return cs;
}
void CardStack::shuffle()
{
	this->cards.shuffle();
}

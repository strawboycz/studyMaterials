#include <iostream>

#include "CardStack.h"
#include "CardStackIterator.h"

int main(int argc, char* argv[])
{
	CardStack *cs = new CardStack();
	cs = cs->createSevenToAceDeck();
	cs->shuffle();
	CardStackIterator csi = CardStackIterator(&cs->cards);
	while (csi.hasNext())
	{
		cout << csi.next().toString() << endl; 
	}

}

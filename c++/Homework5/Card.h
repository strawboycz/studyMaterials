#pragma once
#include <string>
using namespace std;
class Card
{
public:
	enum CardSymbol { none, spades, clubs, diamonds, hearts };
	Card() = default;
	Card(int value, CardSymbol symbol);
	CardSymbol getSymbol();
	int getValue();
	string toString();
private:
	CardSymbol symbol;
	int value;
};

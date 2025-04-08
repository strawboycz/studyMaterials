#include "Card.h"

#include <exception>

Card::Card(int value, CardSymbol symbol) : symbol(symbol)
{
	if (value < 1 || value > 13)
	{
		throw new std::exception;
	}
	this->value = value;
}
Card::CardSymbol Card::getSymbol()
{
	return symbol;
}
int Card::getValue()
{
	return value;
}
string Card::toString()
{
	string output = "";
	switch (this->value)
	{
		case 1: output += "A"; break;
		case 11: output += "J"; break;
		case 12: output += "Q"; break;
		case 13: output += "K"; break;
		default: output += std::to_string(this->value); break;
	}
	switch (this->symbol)
	{
	case hearts: output += " of hearts"; break;
	case spades: output += " of spades"; break;
	case clubs: output += " of clubs"; break;
	case diamonds: output += " of diamonds"; break;
	case none: output += ""; break;
	}
	return output;
}

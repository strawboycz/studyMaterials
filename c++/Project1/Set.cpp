#pragma once
#include "Set.h"
#include <iterator>
#include <sstream>
#include <string>
using namespace std;


	Set::Set(int length) : length(length)
	{
		count = 0;
		array = new int[length];
	}
	Set::~Set()
	{
		delete[] array;
	}
	int Set::getCount()
	{
		return this->count;
	}
	int Set::getAt(int i)
	{
		return array[i];
	}
	bool Set::push(int value)
	{
		if (count == length) return false;
		if (this->contains(value)) return false;
		array[count++] = value;
		return true;
	}
	Set* Set::getUnion(Set* secondSet)
	{
		Set* outp = new Set(this->count + secondSet->getCount());
		for (int i = 0; i < this->count; ++i)
		{
			if (outp->contains(this->getAt(i))) continue;
			outp->push(this->getAt(i));
		}
		for (int i = 0; i < secondSet->getCount(); ++i)
		{
			if (outp->contains(secondSet->getAt(i))) continue;
			outp->push(secondSet->getAt(i));
		}
		return outp;
	}
	Set* Set::getComplement(Set* secondSet)
	{
		Set* outp = new Set(this->count);
		int counter = 0;
		for (int i = 0; i < this->count; ++i)
		{
			if (secondSet->contains(this->getAt(i))) continue;
			outp->push(this->getAt(i));
		}
		return outp;
	}
	std::string Set::toString()
	{
		ostringstream os;
		os << "{";
		for (int i = 0; i < this->count; ++i)
		{
			os << this->getAt(i);
			if (i != this->count - 1) os << ", ";
		}
		os << "}\n";
		return os.str();
	}
	bool Set::contains(int value)
	{
		for (int i = 0; i < count; ++i)
		{
			if (this->getAt(i) == value) return true;
		}
		return false;
	}


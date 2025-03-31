#include "DynamicArray.h"

#include <exception>
#include <iostream>
#include <sstream>

using namespace std;

static unsigned int defaultsize = 5;

DynamicArray::DynamicArray() : counter(0), length(defaultsize)
{
	this->data = new int[length];
}

DynamicArray::DynamicArray(unsigned int n): counter(0) , length(n)
{
	this->data = new int[length];
}

DynamicArray::DynamicArray(int* arr,unsigned int length) : length(length * 2)
{
	this->data = new int[this->length];
	this->counter = 0;
	for (counter; counter < length; counter++)
	{
		this->data[counter] = arr[counter];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] data;
}

int DynamicArray::getAt(unsigned int index)
{
	if (index >= counter)
	{
		cout << "Invalid index!" << endl;
		return -1;
	}
	return this->data[index];
}

void DynamicArray::setAt(unsigned int index, int value)
{
	if (index >= counter)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	this->data[index] = value;
}

void DynamicArray::add(int number)
{
	if (counter >= length)
	{
		this->length *= 2;
		int* newArray = new int[length];
		for (int i = 0; i < counter; ++i)
		{
			newArray[i] = this->data[i];
		}
		delete[] this->data;
		this->data = newArray;
	}

	this->data[counter++] = number;
}

void DynamicArray::removeAt(unsigned int index)
{
	if (index >= counter)
	{
		cout << "Invalid index!" << endl;
		return;
	}
	for (int i = index; i < counter - 1; ++i)
	{
		this->data[i] = this->data[i + 1];
	}
	counter--;
}

string DynamicArray::toString()
{
	if (counter == 0) return "{ }";
	stringbuf sb;
	ostream os(&sb);
	os << "{ ";
	for (int i = 0; i < this->counter - 1; ++i)
	{
		os << this->data[i] << ", ";
	}
	os << this->data[this->counter - 1] << " }";
	return sb.str();
}


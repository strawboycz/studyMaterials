#include "DynamicArray.h"

#include <exception>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

#include "Card.h"

using namespace std;

static unsigned int defaultsize = 5;

DynamicArray::DynamicArray() : counter(0), length(defaultsize)
{
  this->data = new Card[length];
}

DynamicArray::DynamicArray(unsigned int n) : counter(0), length(n)
{
  this->data = new Card[length];
}

DynamicArray::DynamicArray(Card* arr, unsigned int length) : length(length * 2)
{
  this->data = new Card[this->length];
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

Card DynamicArray::getAt(unsigned int index)
{
  if (index >= counter)
  {
    cout << "Invalid index!" << endl;
    return Card();
  }
  return this->data[index];
}

void DynamicArray::setAt(unsigned int index, Card value)
{
  if (index >= counter)
  {
    cout << "Invalid index!" << endl;
    return;
  }
  this->data[index] = value;
}

void DynamicArray::add(Card card)
{
  if (counter >= length)
  {
    this->length *= 2;
    Card* newArray = new Card[length];
    for (int i = 0; i < counter; ++i)
    {
      newArray[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newArray;
  }

  this->data[counter++] = card;
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
    os << this->data[i].toString() << ", ";
  }
  os << this->data[this->counter - 1].toString() << " }";
  return sb.str();
}
int DynamicArray::size()
{
  return counter;
}
void DynamicArray::shuffle()
{
  DynamicArray *shuffled = new DynamicArray();
  vector<int> indexes;
  for (int i = 0; i < this->counter; i++) indexes.push_back(i);
  default_random_engine rd;
  mt19937 gen(rd);
  uniform_int_distribution<int> distribution;
  while (!indexes.empty())
  {
    distribution = uniform_int_distribution<int>(0, indexes.size() - 1);
    int random = distribution(gen);
    int randomIndex = indexes.at(random);
    shuffled->add(this->data[randomIndex]);
    indexes.erase(indexes.begin() + random);
  }
  this->data = shuffled->getData();

}
Card* DynamicArray::getData()
{
  return data;
}

#include "CardStackIterator.h"
CardStackIterator::CardStackIterator(DynamicArray* data) : cards(data), currentIndex(0)
{

}
bool CardStackIterator::hasNext()
{
	return currentIndex < cards->size() ? true : false;
}
Card CardStackIterator::next()
{
  if (!hasNext())
  {
    throw std::exception("No more elements in CardStackIterator");
  }
  return cards->getAt(currentIndex++);
}
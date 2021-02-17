#include "Bubble.h"

Bubble::Bubble()
{
	firstIterator = 0;
	secondIterator = 1;
}

void Bubble::sortArray(std::vector<int> &vec)
{
	if (vec[firstIterator] > vec[secondIterator])
		std::iter_swap(vec.begin() + firstIterator, vec.begin() + secondIterator);


	updateIterators(vec.size());
	
	//sortingSlowDown();
}

void Bubble::updateIterators(int arraySize)
{
	firstIterator++;
	secondIterator++;
	if (secondIterator >= arraySize) {
		firstIterator = 0;
		secondIterator = 1;
	}
}

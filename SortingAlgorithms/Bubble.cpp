#include "Bubble.h"

void Bubble::sortArray()
{
	if (vector[firstIterator] > vector[secondIterator]) {
		std::iter_swap(vector.begin() + firstIterator, vector.begin() + secondIterator);

		updateColorArray(vector[firstIterator]);
	}

	updateIterators(vector.size());
	
	sortingSlowDown();
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

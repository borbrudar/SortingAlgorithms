#include "Selection.h"

void Selection::sortArray()
{
	parseThroughArray();
	updateIterator();
	sortingSlowDown();
}


void Selection::parseThroughArray()
{
	if (vector[iterator] < currentMinimum) {
		currentMinimum = vector[iterator];
		currentLowestIndex = iterator;
	}
		
	if(isParsing) iterator++;
}

void Selection::updateIterator()
{
	if (iterator == vector.size()) {
		updateColorArray(vector[currentLowestIndex]);

		std::iter_swap(vector.begin() + checkArrayFrom, vector.begin() + currentLowestIndex);
		checkArrayFrom++;
		iterator = checkArrayFrom;
		currentMinimum = 1000000;

		if (checkArrayFrom == (vector.size() - 1)) isParsing = false;
	}
}

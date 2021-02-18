#include "Selection.h"

void Selection::sortArray(std::vector<int>& vec)
{
	parseThroughArray(vec);
	updateIterator(vec);
	//sortingSlowDown();
}


void Selection::parseThroughArray(std::vector<int>& vec)
{
	if (vec[iterator] < currentMinimum) {
		currentMinimum = vec[iterator];
		currentLowestIndex = iterator;
	}
	iterator++;
}

void Selection::updateIterator(std::vector<int>& vec)
{
	if (iterator == vec.size()) {
		updateColorArray(vec[currentLowestIndex]);

		std::iter_swap(vec.begin() + checkArrayFrom, vec.begin() + currentLowestIndex);
		checkArrayFrom++;
		iterator = checkArrayFrom;
		currentMinimum = 1000000;
	}
}

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
}

void Selection::updateIterator(std::vector<int>& vec)
{
	iterator++;
	if (iterator == vec.size()) {
		std::iter_swap(vec.begin() + checkArrayFrom, vec.begin() + currentLowestIndex);
		checkArrayFrom++;
		iterator = checkArrayFrom;
		currentMinimum = 1000000;
	}
}

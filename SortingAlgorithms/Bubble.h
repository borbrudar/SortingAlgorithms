#pragma once
#include "SortingAlgorithm.h"


class Bubble : public SortingAlgorithm {
public:
	Bubble() {
		algorithmName = "Bubble";
	}
	void sortArray(std::vector<int>& vec);
private:
	void updateIterators(int arraySize);
	int firstIterator = 0, secondIterator = 1;
};
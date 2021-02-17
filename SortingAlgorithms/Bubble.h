#pragma once
#include "SortingAlgorithm.h"


class Bubble : public SortingAlgorithm {
public:
	Bubble();
	void sortArray(std::vector<int>& vec);
private:
	void updateIterators(int arraySize);
};
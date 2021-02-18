#pragma once
#include "SortingAlgorithm.h"

class Insertion : public SortingAlgorithm {
public:
	void sortArray(std::vector<int>& vec);

	int iterator = 1;
};
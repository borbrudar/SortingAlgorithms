#pragma once
#include "SortingAlgorithm.h"

class Quick : public SortingAlgorithm {
public:
	Quick() {
		algorithmName = "Quick";
	}

	void sortArray(std::vector<int>& vec);
};

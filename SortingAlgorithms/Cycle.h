#pragma once
#include "SortingAlgorithm.h"
#include <random>

class Cycle : public SortingAlgorithm {
public:
	Cycle() {
		algorithmName = "Cycle";
	}

	void sortArray(std::vector<int>& vec);
private:
	void sortCycles(std::vector<int>& vec);
	void chooseNextCycle(int number);
	
	std::vector<int> sortedValues;
	int nextValue = 0;
	bool isParsing = true;
};
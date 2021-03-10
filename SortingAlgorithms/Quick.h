#pragma once
#include "SortingAlgorithm.h"
#include "QuickTree.h"

class Quick : public SortingAlgorithm {
public:
	Quick() {
		algorithmName = "Quick";
	}

	void sortArray();
	QuickTree quick;
	bool isInit = false;
};

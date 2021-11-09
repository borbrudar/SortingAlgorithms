#pragma once
#include "SortingAlgorithm.h"

class Insertion : public SortingAlgorithm {
public:
	Insertion() {
		algorithmName = "Insertion";
	}
	void sortArray();

	int iterator = 1;
};
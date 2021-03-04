#pragma once
#include "SortingAlgorithm.h"
#include "Bucket.h"

class Merge : public SortingAlgorithm {
public:
	Merge() {
		algorithmName = "Merge";
	}
	void sortArray(std::vector<int>& vec);
private:
	Bucket bucket;
	bool isInit = false;
};
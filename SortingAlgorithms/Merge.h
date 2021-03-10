#pragma once
#include "SortingAlgorithm.h"
#include "Bucket.h"

class Merge : public SortingAlgorithm {
public:
	Merge() {
		algorithmName = "Merge";
	}
	void sortArray();
private:
	Bucket bucket;
	bool isInit = false;
};
#pragma once
#include "SortingAlgorithm.h"

class Merge : public SortingAlgorithm {
public:
	void sortArray();
private:
	void split(int l,int r);
};
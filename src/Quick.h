#pragma once
#include "SortingAlgorithm.h"

class Quick : public SortingAlgorithm {
public:
	void sortArray();
private:	
	void sort(int l,int r);
};

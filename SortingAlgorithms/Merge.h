#pragma once
#include "SortingAlgorithm.h"

class Merge : public SortingAlgorithm {
public:
	void sortArray(std::vector<int>& vec);
private:
	std::vector<int> mergeSort(std::vector<int>& vec1, std::vector<int> &vec2);
	void resetIterators();
	void updateIterators(std::vector<int>& sortedVec, std::vector<int>& vec, int& itr);
	void pushRemainingElements(std::vector<int> &sortedVec, std::vector<int>& vec, int& itr);

	int firstIterator = 0, secondIterator = 0;
};
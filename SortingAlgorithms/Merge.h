#pragma once
#include "SortingAlgorithm.h"

class Merge : public SortingAlgorithm {
public:
	Merge() {
		algorithmName = "Merge";
	}
	void sortArray(std::vector<int>& vec);
private:
	std::vector<std::vector<int>> splitArray(std::vector<std::vector<int>> &vec);
	std::vector<std::vector<int>> mergeSort(std::vector<std::vector<int>>& vec1, std::vector<std::vector<int>> &vec2);
	void resetIterators();
	void updateIterators(std::vector<std::vector<int>>& sortedVec, std::vector<std::vector<int>>& vec, int& itr);
	void pushRemainingElements(std::vector<std::vector<int>> &sortedVec, std::vector<std::vector<int>>& vec, int& itr);

	int firstIterator = 0, secondIterator = 0;
	bool isSorted = 0;

	std::vector<int> stepColorArray;
	int colorItr = 0;
	std::vector<int> leftSwap;
	std::vector<int> rightSwap;
	int swapItr = 0;

};
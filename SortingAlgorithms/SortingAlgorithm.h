#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class SortingAlgorithm {
public:
	virtual void sortArray(std::vector<int> &vec) = 0;
	void sortingSlowDown();
protected:
	int firstIterator = 0, secondIterator = 0;
	int sleepForInMiliseconds = 1;
};
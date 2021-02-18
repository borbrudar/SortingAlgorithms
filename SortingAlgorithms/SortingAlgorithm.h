#pragma once
#include <vector>
#include <deque>
#include <string>
#include <SFML/Graphics.hpp>

class SortingAlgorithm {
public:
	virtual void sortArray(std::vector<int> &vec) = 0;
	void sortingSlowDown();
	void updateColorArray(int indexToAdd);

	std::deque<int> getColorArray();
	int getMaxColorArraySize();
	std::string getAlgorithmName();
protected:
	std::deque<int> colorArray;
	int maxColorArraySize = 10;
	int sleepForInMiliseconds = 30;
	std::string algorithmName;
};
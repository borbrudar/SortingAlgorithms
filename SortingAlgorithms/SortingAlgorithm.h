#pragma once
#include <vector>
#include <deque>
#include <SFML/Graphics.hpp>

class SortingAlgorithm {
public:
	virtual void sortArray(std::vector<int> &vec) = 0;

	std::string getAlgorithmName();

	std::deque<int> getColorArray();
	int getMaxColorArraySize();

	void setSleepInMiliseconds(int miliseconds);
	int getSleepInMiliseconds();

protected:
	void sortingSlowDown();
	void updateColorArray(int indexToAdd);

	std::deque<int> colorArray;
	int maxColorArraySize = 10;
	int sleepForInMiliseconds = 30;
	std::string algorithmName;
};
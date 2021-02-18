#include "SortingAlgorithm.h"

std::deque<int> SortingAlgorithm::getColorArray()
{
	return colorArray;
}

int SortingAlgorithm::getMaxColorArraySize()
{
	return maxColorArraySize;
}

std::string SortingAlgorithm::getAlgorithmName()
{
	return algorithmName;
}

void SortingAlgorithm::sortingSlowDown()
{
	sf::Time time = sf::milliseconds(sleepForInMiliseconds);
	sf::sleep(time);
}

void SortingAlgorithm::updateColorArray(int indexToAdd)
{
	colorArray.push_back(indexToAdd);
	if (colorArray.size() >= maxColorArraySize) colorArray.pop_front();
}

#include "GameState.h"

void GameState::sortArray()
{
	sortingAlgorithm->sortArray(unsortedArray);
}

void GameState::randomizeUnsortedArray()
{
	int arraySize = 64;

	std::vector<int> sortedArray;
	sortedArray.resize(arraySize);
	unsortedArray.resize(arraySize);

	std::random_device rd;
	std::default_random_engine engine(rd());

	for (int i = 0; i < sortedArray.size(); i++) sortedArray[i] = i;
	for (int i = 0; i < unsortedArray.size(); i++) {
		std::uniform_int_distribution<int> dist(0, sortedArray.size() - 1);
		int randomValueFromSortedArray = dist(engine);

		unsortedArray[i] = sortedArray[randomValueFromSortedArray];
		sortedArray.erase(sortedArray.begin() + randomValueFromSortedArray);
	}
}

std::vector<int> GameState::getUnsortedArray()
{
	return unsortedArray;
}

std::unique_ptr<SortingAlgorithm>& GameState::getSortingAlgorithm()
{
	return sortingAlgorithm;
}

#include "GameState.h"

void GameState::init(RenderWindow& window, Vector2f size)
{
	sortingAlgorithm = std::make_unique<Insertion>();
	randomizeUnsortedArray();

	draw1.init(window, size);
}

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

void GameState::drawGameState(RenderWindow& window)
{
	Color backgroundColor = Color(64, 64, 64);

	window.clear(backgroundColor);
	std::deque<int> temp = sortingAlgorithm->getColorArray();
	draw1.drawArray(window, unsortedArray, temp);

	std::string algName = "Using: " + sortingAlgorithm->getAlgorithmName() + " Sort";
	draw1.drawString(window, Vector2f(20, 20), algName);
	window.display();
}

std::vector<int> GameState::getUnsortedArray()
{
	return unsortedArray;
}

std::unique_ptr<SortingAlgorithm>& GameState::getSortingAlgorithm()
{
	return sortingAlgorithm;
}

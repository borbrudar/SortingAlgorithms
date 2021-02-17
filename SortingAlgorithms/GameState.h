#pragma once
#include <vector>
#include <random>
#include <memory>
#include "SortingAlgorithm.h"
#include "Bubble.h"


class GameState {
public:
	GameState() {
		sortingAlgorithm = std::make_unique<Bubble>();
		randomizeUnsortedArray();
	}
	void sortArray();
	void randomizeUnsortedArray();
	std::vector<int> getUnsortedArray();

private:
	std::vector<int> unsortedArray;
	std::unique_ptr<SortingAlgorithm> sortingAlgorithm;
};
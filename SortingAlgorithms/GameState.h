#pragma once
#include <vector>
#include <random>
#include <memory>
#include "SortingAlgorithm.h"
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Cycle.h"
#include "Merge.h"

class GameState {
public:
	GameState();
	void init();
	void sortArray();
	std::vector<int> getUnsortedArray();
	std::unique_ptr<SortingAlgorithm>& getSortingAlgorithm();
private:
	void randomizeUnsortedArray();
	std::vector<int> unsortedArray;
	std::unique_ptr<SortingAlgorithm> sortingAlgorithm;
};
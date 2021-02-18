#pragma once
#include <vector>
#include <random>
#include <memory>
#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Draw.h"


class GameState {
public:
	void init(RenderWindow& window, Vector2f size);
	void sortArray();
	void randomizeUnsortedArray();
	void drawGameState(RenderWindow &window);
	std::vector<int> getUnsortedArray();
	std::unique_ptr<SortingAlgorithm>& getSortingAlgorithm();
private:
	std::vector<int> unsortedArray;
	std::unique_ptr<SortingAlgorithm> sortingAlgorithm;

	Draw draw1;
};
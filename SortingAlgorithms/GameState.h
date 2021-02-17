#pragma once
#include <vector>
#include <random>

class GameState {
public:
	GameState() {
		randomizeUnsortedArray();
	}

	void randomizeUnsortedArray();
	std::vector<int> unsortedArray;
};
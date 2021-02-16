#pragma once
#include <vector>

class GameState {
public:
	GameState() {
		unsortedArray.resize(256);
		for (int i = 0; i < unsortedArray.size(); i++) {
			unsortedArray[i] = i;
		}
	}
	std::vector<int> unsortedArray;
};
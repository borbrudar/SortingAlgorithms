#pragma once
#include <vector>
#include <deque>
#include <SFML/Graphics.hpp>
#include "config.h"
#include <random>

using namespace sf;
class SortingAlgorithm {
public:
	virtual void sortArray() = 0;
	void randomize();
	bool verify();

	std::vector<int> getVec() { return vec;};
	std::vector<std::pair<int,int>> getSwaps() { return swaps; };
protected:
	std::vector<int> vec;
	std::vector<std::pair<int,int>> swaps; // index, new_val
};
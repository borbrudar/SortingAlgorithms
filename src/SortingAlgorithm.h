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
protected:
	std::vector<int> vec;
	std::vector<std::vector<int>> swaps;
};
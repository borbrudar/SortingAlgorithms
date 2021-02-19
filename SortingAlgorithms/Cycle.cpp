#include "Cycle.h"

void Cycle::sortArray(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == nextValue) {
			if (nextValue == i) chooseNextCycle(vec.size());

			sortedValues.push_back(nextValue);
			std::iter_swap(vec.begin() + nextValue, vec.begin() + i);
			nextValue = vec[i];
			updateColorArray(vec[i]);

			break;
		}
	}

	sortingSlowDown();
}

void Cycle::chooseNextCycle(int vecSize)
{
	bool nextCycleChosen = false;

	std::random_device rd;
	std::default_random_engine engine(rd());
	std::uniform_int_distribution<int> dist(0, vecSize - 1);
	int randomNumber;

	while (!nextCycleChosen) {
		randomNumber = dist(engine);
		nextCycleChosen = 1;
		for (int i = 0; i < sortedValues.size(); i++) {
			if (sortedValues[i] == randomNumber) {
				nextCycleChosen = 0;
				break;
			}
		}

	}

	nextValue = randomNumber;
}

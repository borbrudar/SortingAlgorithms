#include "Cycle.h"

void Cycle::sortArray(std::vector<int>& vec)
{
	if (isParsing) sortCycles(vec);
	sortingSlowDown();
}

void Cycle::sortCycles(std::vector<int>& vec)
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
}

void Cycle::chooseNextCycle(int vecSize)
{
	int nextCycleBegging = 0;

	for (int i = 0; i < sortedValues.size(); i++) {
		if (nextCycleBegging == sortedValues[i]) {
			nextCycleBegging++;
			i = 0; 
			continue;
		}
	}

	if (nextCycleBegging == vecSize) isParsing = false;
	else nextValue = nextCycleBegging;

}

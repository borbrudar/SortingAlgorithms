#include "Cycle.h"

void Cycle::sortArray()
{
	if (isParsing) sortCycles();
	sortingSlowDown();
}

void Cycle::sortCycles()
{
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i] == nextValue) {
			if (nextValue == i) chooseNextCycle(vector.size());

			sortedValues.push_back(nextValue);
			std::iter_swap(vector.begin() + nextValue, vector.begin() + i);
			nextValue = vector[i];
			updateColorArray(vector[i]);

			break;
		}
	}
}

void Cycle::chooseNextCycle(int vectorSize)
{
	int nextCycleBegging = 0;

	for (int i = 0; i < sortedValues.size(); i++) {
		if (nextCycleBegging == sortedValues[i]) {
			nextCycleBegging++;
			i = 0; 
			continue;
		}
	}

	if (nextCycleBegging == vectorSize) isParsing = false;
	else nextValue = nextCycleBegging;

}

#include "Insertion.h"

void Insertion::sortArray(std::vector<int>& vec)
{

	for (int i = 0; i < iterator; i++) {
		if (vec[iterator] < vec[i]) {
			int temp = vec[iterator];
			vec.erase(vec.begin() + iterator);
			vec.insert(vec.begin() + i,temp);
			

			updateColorArray(vec[i]);
		}
	}

	if(iterator < (vec.size() - 1)) iterator++;

	sortingSlowDown();
}

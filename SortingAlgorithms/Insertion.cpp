#include "Insertion.h"

void Insertion::sortArray()
{

	for (int i = 0; i < iterator; i++) {
		if (vector[iterator] < vector[i]) {
			int temp = vector[iterator];
			vector.erase(vector.begin() + iterator);
			vector.insert(vector.begin() + i,temp);
			

			updateColorArray(vector[i]);
		}
	}

	if(iterator < (vector.size() - 1)) iterator++;

}

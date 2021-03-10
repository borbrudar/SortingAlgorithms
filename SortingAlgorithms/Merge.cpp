#include "Merge.h"

void Merge::sortArray()
{
	if (!isInit) {
		bucket.init(vector);
		isInit = true;
	}

	bucket.sortBucket();
	vector = bucket.updateBucket();
	updateColorArray(bucket.color);

	sortingSlowDown();
}


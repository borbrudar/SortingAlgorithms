#include "Merge.h"

void Merge::sortArray(std::vector<int>& vec)
{
	if (!isInit) {
		bucket.init(vec);
		isInit = true;
	}

	bucket.sortBucket();
	vec = bucket.updateBucket();
	updateColorArray(bucket.color);

	sortingSlowDown();
}


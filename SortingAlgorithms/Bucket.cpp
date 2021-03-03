#include "Bucket.h"

Bucket::Bucket(std::vector<int> array) 
{
	bucketArray = array;
	setupNewNodes();
}

Bucket::~Bucket()
{
	delete left;
	delete right;
}

void Bucket::setupNewNodes()
{
	// for some reason it doesnt work in a single statement
	// so here will this temp variable stay
	float vecSize = bucketArray.size();
	int midpoint = std::ceilf(vecSize / 2);

	if (vecSize == 1) {
		isLeaf = true; 
		return;
	}

	std::vector<int> leftArr;
	leftArr.resize(midpoint);
	for (int i = 0; i < leftArr.size(); i++) leftArr[i] = bucketArray[i];

	std::vector<int> rightArr;
	rightArr.resize(bucketArray.size() - midpoint);
	for (int i = midpoint, right = 0; i < bucketArray.size(); i++, right++) rightArr[right] = bucketArray[i];

	left = new Bucket(leftArr);
	right = new Bucket(rightArr);
}

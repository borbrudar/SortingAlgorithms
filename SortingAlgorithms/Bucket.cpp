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

void Bucket::sortBucket()
{
	if (left->isLeaf && right->isLeaf) 	mergeNodes();
	else if (left->isLeaf) left->sortBucket();
	else right->sortBucket();

}

void Bucket::mergeNodes()
{
	for (int firstIterator = 0, secondIterator = 0;
		firstIterator < left->bucketArray.size() || secondIterator < right->bucketArray.size();) {

		if (left->bucketArray[firstIterator] < right->bucketArray[secondIterator]) {

			if(firstIterator > left->bucketArray.size())
		}
	}

	while (true) {
		if (vec1[firstIterator] < vec2[secondIterator]) {

			if (firstIterator > (vec1.size() - 1)) {
				pushRemainingElements(sortedVec, vec2, secondIterator);
				resetIterators();
				return sortedVec;
			}
		}
		else {
			updateIterators(sortedVec, vec2, secondIterator);

			if (secondIterator > (vec2.size() - 1)) {
				pushRemainingElements(sortedVec, vec1, firstIterator);
				resetIterators();
				return sortedVec;
			}
		}
	}


	delete left;
	delete right;
	isLeaf = true;
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

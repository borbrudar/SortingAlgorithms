#include "Bucket.h"

Bucket::Bucket(std::vector<int> array)
{
	init(array);
}

Bucket::~Bucket()
{
}

void Bucket::init(std::vector<int> array)
{
	bucketArray = array;
	setupNewNodes();
}

void Bucket::sortBucket()
{
	if (left->isLeaf && right->isLeaf) 	mergeNodes();
	else if (!left->isLeaf) left->sortBucket();
	else right->sortBucket();

}

std::vector<int> Bucket::updateBucket()
{
	updateNodes();

	return bucketArray;
}

void Bucket::updateNodes()
{
	if (isLeaf) return;
	left->updateNodes();
	right->updateNodes();

	bucketArray.clear();
	for (int i = 0; i < left->bucketArray.size(); i++) bucketArray.push_back(left->bucketArray[i]);
	for (int i = 0; i < right->bucketArray.size(); i++) bucketArray.push_back(right->bucketArray[i]);
}

void Bucket::mergeNodes()
{
	bucketArray.clear();
	for (int firstIterator = 0, secondIterator = 0;
		firstIterator < left->bucketArray.size() || secondIterator < right->bucketArray.size();) {

		if (left->bucketArray[firstIterator] < right->bucketArray[secondIterator]) {
			bucketArray.push_back(left->bucketArray[firstIterator]);
			firstIterator++;

			if (firstIterator >= left->bucketArray.size()) {
				for (; secondIterator < right->bucketArray.size(); secondIterator++) 
					bucketArray.push_back(right->bucketArray[secondIterator]);
				break;
			}
		}
		else {
			bucketArray.push_back(right->bucketArray[secondIterator]);
			secondIterator++;

			if (secondIterator >= right->bucketArray.size()) {
				for (; firstIterator < left->bucketArray.size(); firstIterator++)
					bucketArray.push_back(left->bucketArray[firstIterator]);
				break;
			}
		}
	}

	isLeaf = true;
}

void Bucket::setupNewNodes()
{
	// for some reason it doesnt work in a single statement
	// so here will this temp variable stay
	float vecSize = bucketArray.size();
	float midpoint = std::ceilf(vecSize / 2.f);

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

void Bucket::pushRemainingElements(bool isLeft, int& itr)
{
	if (isLeft);
	else for (; itr < bucketArray.size(); itr++) bucketArray.push_back(right->bucketArray[itr]);
	
}

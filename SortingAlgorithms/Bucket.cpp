#include "Bucket.h"

Bucket::Bucket(std::vector<int> array)
{
	init(array);
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
	if(!isMerging) color = -1;
	if (isLeaf || isMerging) return;

	if (left->color != -1) color = left->color;
	else if (right->color != -1) color = left->bucketArray.size() + right->color;
	
	left->updateNodes();
	right->updateNodes();

	bucketArray.clear();

	for (int i = 0; i < left->bucketArray.size(); i++) bucketArray.push_back(left->bucketArray[i]);
	for (int i = 0; i < right->bucketArray.size(); i++) bucketArray.push_back(right->bucketArray[i]);
}

void Bucket::mergeNodes()
{
	color = -1;
	isMerging = true;
	bucketArray.erase(bucketArray.begin() + firstIterator + secondIterator, bucketArray.end());

	for (;firstIterator < left->bucketArray.size() ||
		secondIterator < right->bucketArray.size();) {

		if (left->bucketArray[firstIterator] < right->bucketArray[secondIterator]) {
			bucketArray.push_back(left->bucketArray[firstIterator]);
			firstIterator++;

			if (firstIterator >= left->bucketArray.size()) {
				for (; secondIterator < right->bucketArray.size(); secondIterator++) 
					bucketArray.push_back(right->bucketArray[secondIterator]);
				break;
			}


			for (int i = firstIterator; i < left->bucketArray.size(); i++) bucketArray.push_back(left->bucketArray[i]);
			for (int i = secondIterator; i < right->bucketArray.size(); i++) bucketArray.push_back(right->bucketArray[i]);
			color = firstIterator + secondIterator - 1;
			return;
		}
		else {
			bucketArray.push_back(right->bucketArray[secondIterator]);
			secondIterator++;

			if (secondIterator >= right->bucketArray.size()) {
				for (; firstIterator < left->bucketArray.size(); firstIterator++)
					bucketArray.push_back(left->bucketArray[firstIterator]);
				break;
			}


			for (int i = firstIterator; i < left->bucketArray.size(); i++) bucketArray.push_back(left->bucketArray[i]);
			for (int i = secondIterator; i < right->bucketArray.size(); i++) bucketArray.push_back(right->bucketArray[i]);
			color = firstIterator + secondIterator - 1;
			return;
		}
	}

	isMerging = false;
	isLeaf = true;
}

void Bucket::setupNewNodes()
{
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


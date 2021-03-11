#include "Bucket.h"

Bucket::Bucket(std::vector<int>& vec)
{
	init(vec);
}

void Bucket::init(std::vector<int> &vec)
{
	bucketArray = vec;
	setupNewNodes();
}

void Bucket::sortBucket()
{
	if (path[0]->isLeaf && path[1]->isLeaf) 	mergeNodes();
	else if (!path[0]->isLeaf) path[0]->sortBucket();
	else path[1]->sortBucket();

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

	if (path[0]->color != -1) color = path[0]->color;
	else if (path[1]->color != -1) color = path[0]->bucketArray.size() + path[1]->color;
	
	path[0]->updateNodes();
	path[1]->updateNodes();

	bucketArray.clear();

	for (int i = 0; i < path[0]->bucketArray.size(); i++) bucketArray.push_back(path[0]->bucketArray[i]);
	for (int i = 0; i < path[1]->bucketArray.size(); i++) bucketArray.push_back(path[1]->bucketArray[i]);
}

void Bucket::mergeNodes()
{
	color = -1;
	isMerging = true;
	bucketArray.erase(bucketArray.begin() + mainIterator[0] + mainIterator[1], bucketArray.end());

	for (;mainIterator[0] < path[0]->bucketArray.size() ||
		mainIterator[1] < path[1]->bucketArray.size();) {

		int first, second;

		if (path[0]->bucketArray[mainIterator[0]] < path[1]->bucketArray[mainIterator[1]]) {
			first = 0; second = 1;
		}
		else {
			first = 1; second = 0;
		}

		bucketArray.push_back(path[first]->bucketArray[mainIterator[first]]);
		mainIterator[first];

		if (mainIterator[first] >= path[first]->bucketArray.size()) {
			for (; mainIterator[second] < path[second]->bucketArray.size(); mainIterator[second]++) 
				bucketArray.push_back(path[second]->bucketArray[mainIterator[second]]);
			break;
		}


		for (int i = mainIterator[0]; i < path[0]->bucketArray.size(); i++) bucketArray.push_back(path[0]->bucketArray[i]);
		for (int i = mainIterator[1]; i < path[1]->bucketArray.size(); i++) bucketArray.push_back(path[1]->bucketArray[i]);
		color = mainIterator[0] + mainIterator[1] - 1;
		return;
		
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

	path[0] = new Bucket(leftArr);
	path[1] = new Bucket(rightArr);
}


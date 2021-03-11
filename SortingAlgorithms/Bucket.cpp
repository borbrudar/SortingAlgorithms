#include "Bucket.h"

Bucket::Bucket(std::vector<int>& vec)
{
	init(vec);
}

void Bucket::init(std::vector<int> &vec)
{
	dataVector = vec;
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

	return dataVector;
}

void Bucket::updateNodes()
{
	if(!isMerging) color = -1;
	if (isLeaf || isMerging) return;

	if (path[0]->color != -1) color = path[0]->color;
	else if (path[1]->color != -1) color = path[0]->dataVector.size() + path[1]->color;
	
	path[0]->updateNodes();
	path[1]->updateNodes();

	dataVector.clear();

	for (int i = 0; i < path[0]->dataVector.size(); i++) dataVector.push_back(path[0]->dataVector[i]);
	for (int i = 0; i < path[1]->dataVector.size(); i++) dataVector.push_back(path[1]->dataVector[i]);
}

void Bucket::mergeNodes()
{
	color = -1;
	isMerging = true;
	dataVector.erase(dataVector.begin() + mainIterator[0] + mainIterator[1], dataVector.end());

	for (;mainIterator[0] < path[0]->dataVector.size() ||
		mainIterator[1] < path[1]->dataVector.size();) {

		int first, second;

		if (path[0]->dataVector[mainIterator[0]] < path[1]->dataVector[mainIterator[1]]) {
			first = 0; second = 1;
		}
		else {
			first = 1; second = 0;
		}

		dataVector.push_back(path[first]->dataVector[mainIterator[first]]);
		mainIterator[first]++;

		if (mainIterator[first] >= path[first]->dataVector.size()) {
			for (; mainIterator[second] < path[second]->dataVector.size(); mainIterator[second]++)
				dataVector.push_back(path[second]->dataVector[mainIterator[second]]);
			break;
		}


		for (int i = mainIterator[0]; i < path[0]->dataVector.size(); i++) dataVector.push_back(path[0]->dataVector[i]);
		for (int i = mainIterator[1]; i < path[1]->dataVector.size(); i++) dataVector.push_back(path[1]->dataVector[i]);
		color = mainIterator[0] + mainIterator[1] - 1;
		return;
	}

	isMerging = false;
	isLeaf = true;
}

void Bucket::setupNewNodes()
{
	float vecSize = dataVector.size();
	float midpoint = std::ceilf(vecSize / 2.f);

	if (vecSize == 1) {
		isLeaf = true; 
		return;
	}

	std::vector<int> leftArr;
	leftArr.resize(midpoint);
	for (int i = 0; i < leftArr.size(); i++) leftArr[i] = dataVector[i];

	std::vector<int> rightArr;
	rightArr.resize(dataVector.size() - midpoint);
	for (int i = midpoint, right = 0; i < dataVector.size(); i++, right++) rightArr[right] = dataVector[i];

	path[0] = new Bucket(leftArr);
	path[1] = new Bucket(rightArr);
}


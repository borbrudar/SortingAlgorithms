#include "Bucket.h"
#include <math.h>

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
	if (isMerging || isLeaf) return;

	path[0]->updateNodes();
	path[1]->updateNodes();

	updateNodesBase();
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
	float midpoint = std::ceil(vecSize / 2.f);

	if (vecSize == 1) {
		isLeaf = true; 
		return;
	}

	splitVectorToNodes(midpoint);
}


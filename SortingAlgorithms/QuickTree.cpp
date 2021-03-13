#include "QuickTree.h"

QuickTree::QuickTree(std::vector<int>& vec)
{
	init(vec);
}

void QuickTree::init(std::vector<int>& vec)
{
	dataVector = vec;
}

void QuickTree::sortTree()
{
	if (!isSorting) color = -1;
	if (dataVector.size() <= 1) {
		isSorting = false;
		return;
	}

	if (isSorting) partition();
	else if (path[0]->isSorting || path[0]->areNodesSorting) path[0]->sortTree();
	else if (path[1]->isSorting || path[1]->areNodesSorting) path[1]->sortTree();
	


	if (!isSorting && !areNodesInit) setupNodes();
	if (areNodesInit) {
		if (path[0]->areNodesSorting || path[1]->areNodesSorting) areNodesSorting = true;
		if (!path[0]->areNodesSorting && !path[1]->areNodesSorting
			&& !path[0]->isSorting && !path[1]->isSorting) 	areNodesSorting = false;

	}
}

std::vector<int> QuickTree::updateTree()
{
	updateNodes();

	return dataVector;
}

void QuickTree::partition()
{
	if (j >= (dataVector.size() - 1)) {
		std::iter_swap(dataVector.begin() + 1 + i, dataVector.begin() + pivot);
		pivot = i + 1;
		color = pivot;
		pivotValue = dataVector[pivot];
		isSorting = false;
		return;
	}

	pivot = dataVector.size() - 1;

	if (dataVector[j] <= dataVector[pivot]) {
		i++;
		std::iter_swap(dataVector.begin() + i,dataVector.begin() + j);
		color = j;
	}

	j++;
}

void QuickTree::setupNodes()
{
	float vecSize = dataVector.size();
	float midpoint = pivot;

	if (vecSize == 1) {
		isSorting = false;
		return;
	}

	splitVectorToNodes(midpoint);

	areNodesInit = true;
	areNodesSorting = true;
	isLeaf = false;
}

void QuickTree::updateNodes()
{
	if (isLeaf) return;

	path[0]->updateNodes();
	path[1]->updateNodes();
	
	updateNodesBase();

	dataVector.insert(dataVector.begin() + pivot, pivotValue);
}

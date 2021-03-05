#include "QuickTree.h"

QuickTree::QuickTree(std::vector<int>& vec)
{
	init(vec);
}

void QuickTree::init(std::vector<int>& vec)
{
	treeVec = vec;
}

void QuickTree::sortTree()
{
	if (treeVec.size() <= 1) {
		isSorting = false;
		return;
	}

	//todo nodes are not recursively sorting or setting up nodes
	if (isSorting) partition();
	else if (left->isSorting || left->areNodesSorting) left->sortTree();
	else if (right->isSorting || right->areNodesSorting) right->sortTree();


	if (!isSorting && !areNodesInit) setupNodes();
	

	if (areNodesInit) {
		if (left->areNodesSorting || right->areNodesSorting) areNodesSorting = true;
		if (!left->areNodesSorting && !right->areNodesSorting 
			&& !left->isSorting && !right->isSorting) areNodesSorting = false;
	}
}

std::vector<int> QuickTree::updateTree()
{
	updateNodes();

	return treeVec;
}

void QuickTree::partition()
{
	if (j >= (treeVec.size() - 1)) {
		std::iter_swap(treeVec.begin() + 1 + i, treeVec.begin() + pivot);
		pivot = i + 1;
		pivotValue = treeVec[pivot];
		isSorting = false;
		return;
	}

	pivot = treeVec.size() - 1;

	if (treeVec[j] <= treeVec[pivot]) {
		i++;
		std::iter_swap(treeVec.begin() + i,treeVec.begin() + j);
	}

	j++;
}

void QuickTree::setupNodes()
{
	float vecSize = treeVec.size();
	float midpoint = pivot;

	if (vecSize == 1) {
		isSorting = false;
		return;
	}

	std::vector<int> leftArr;
	leftArr.resize(midpoint);
	for (int i = 0; i < leftArr.size(); i++) leftArr[i] = treeVec[i];

	std::vector<int> rightArr;
	rightArr.resize(treeVec.size() - midpoint - 1);
	for (int i = midpoint + 1, right = 0; i < treeVec.size(); i++, right++) rightArr[right] = treeVec[i];

	left = new QuickTree(leftArr);
	right = new QuickTree(rightArr);

	areNodesInit = true;
	areNodesSorting = true;
	isLeaf = false;
}

void QuickTree::updateNodes()
{
	if (isLeaf) return;

	left->updateNodes();
	right->updateNodes();

	treeVec.clear();

	for (int i = 0; i < left->treeVec.size(); i++) treeVec.push_back(left->treeVec[i]);
	treeVec.push_back(pivotValue);
	for (int i = 0; i < right->treeVec.size(); i++) treeVec.push_back(right->treeVec[i]);
}

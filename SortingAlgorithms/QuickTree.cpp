#include "QuickTree.h"

QuickTree::QuickTree(std::vector<int>& vec)
{
	treeVec = vec;
}

void QuickTree::sortTree()
{
	if (!isSorting && !areNodesInit) setupNodes();
	
	if (isSorting) partition();
	else if (left->isSorting) left->sortTree();
	else right->sortTree();
}

void QuickTree::partition()
{
}

void QuickTree::setupNodes()
{
	float vecSize = treeVec.size();
	float midpoint = std::ceilf(vecSize / 2.f);

	if (vecSize == 1) {
		isSorting = false;
		return;
	}

	std::vector<int> leftArr;
	leftArr.resize(midpoint);
	for (int i = 0; i < leftArr.size(); i++) leftArr[i] = treeVec[i];

	std::vector<int> rightArr;
	rightArr.resize(treeVec.size() - midpoint);
	for (int i = midpoint, right = 0; i < treeVec.size(); i++, right++) rightArr[right] = treeVec[i];

	left = new QuickTree(leftArr);
	right = new QuickTree(rightArr);
	areNodesInit = true;
}

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
	if (!isSorting) color = -1;
	if (treeVec.size() <= 1) {
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

	return treeVec;
}

void QuickTree::partition()
{
	if (j >= (treeVec.size() - 1)) {
		std::iter_swap(treeVec.begin() + 1 + i, treeVec.begin() + pivot);
		pivot = i + 1;
		color = pivot;
		pivotValue = treeVec[pivot];
		isSorting = false;
		return;
	}

	pivot = treeVec.size() - 1;

	if (treeVec[j] <= treeVec[pivot]) {
		i++;
		std::iter_swap(treeVec.begin() + i,treeVec.begin() + j);
		color = j;
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

	path[0] = new QuickTree(leftArr);
	path[1] = new QuickTree(rightArr);

	areNodesInit = true;
	areNodesSorting = true;
	isLeaf = false;
}

void QuickTree::updateNodes()
{
	if (isLeaf) return;

	path[0]->updateNodes();
	path[1]->updateNodes();

	if (path[0]->color != -1) color = path[0]->color;
	else if (path[1]->color != -1) color = path[0]->treeVec.size() + path[1]->color + 1;
	else if (color == pivot) color = path[0]->treeVec.size();
	else color = -1;

	treeVec.clear();

	for (int i = 0; i < path[0]->treeVec.size(); i++) treeVec.push_back(path[0]->treeVec[i]);
	treeVec.push_back(pivotValue);
	for (int i = 0; i < path[1]->treeVec.size(); i++) treeVec.push_back(path[1]->treeVec[i]);
}

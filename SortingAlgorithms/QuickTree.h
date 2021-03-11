#pragma once
#include <vector>
#include <cmath>
#include "BinaryTree.h"

class QuickTree : public BinaryTree{
public:
	QuickTree() = default;
	QuickTree(std::vector<int>& vec);
	void init(std::vector<int>& vec);

	void sortTree();
	std::vector<int> updateTree();
private:
	void partition();
	void setupNodes();
	void updateNodes();

	std::vector<int> treeVec;
	QuickTree* path[2];
	bool isSorting = true, areNodesInit = false, isLeaf = true, areNodesSorting = false;

	int pivot, j = 0, i = -1;
	int pivotValue;
};
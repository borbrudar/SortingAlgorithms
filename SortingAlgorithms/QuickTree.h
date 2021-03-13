#pragma once
#include <vector>
#include <cmath>
#include "BinaryTree.h"

class QuickTree : public BinaryTree<QuickTree> {
public:
	QuickTree() = default;
	QuickTree(std::vector<int>& vec);
	void init(std::vector<int>& vec);

	void sortTree();
	std::vector<int> updateTree();
private:
	void updateNodes();
	void partition();
	void setupNodes();

	bool isSorting = true, isLeaf = true, areNodesInit = false, areNodesSorting = false;

	int pivot, j = 0, i = -1;
	int pivotValue;
};
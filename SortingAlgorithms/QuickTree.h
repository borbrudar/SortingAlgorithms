#pragma once
#include <vector>
#include <cmath>

class QuickTree {
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
	QuickTree* left;
	QuickTree* right;
	bool isSorting = true, areNodesInit = false, isLeaf = true;

	int pivot, j = 0, i = -1;
	int pivotValue;
};
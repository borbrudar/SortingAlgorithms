#pragma once
#include <vector>
#include <cmath>

class QuickTree {
public:
	QuickTree() = default;
	QuickTree(std::vector<int>& vec);
private:
	void sortTree();
	void partition();
	void setupNodes();

	std::vector<int> treeVec;
	QuickTree* left;
	QuickTree* right;
	bool isSorting = true, areNodesInit = false;
};
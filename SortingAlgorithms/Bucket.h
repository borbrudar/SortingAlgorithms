#pragma once
#include <vector>
#include <cmath>
#include "BinaryTree.h"

class Bucket : public BinaryTree<Bucket>{
public:
	Bucket() = default;
	Bucket(std::vector<int>& vec);
	void init(std::vector<int> &vec);
	void sortBucket();
	std::vector<int> updateBucket();
private:
	void mergeNodes();
	void setupNewNodes();
	void updateNodes();

	bool isLeaf = 0, isMerging = 0;
	int mainIterator[2] = { 0,0 };
};
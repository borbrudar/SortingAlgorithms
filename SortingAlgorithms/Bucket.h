#pragma once
#include <vector>
#include <cmath>
#include "BinaryTree.h"

class Bucket : public BinaryTree{
public:
	Bucket() = default;
	Bucket(std::vector<int>& vec);
	void init(std::vector<int> &vec);
	void sortBucket();
	std::vector<int> updateBucket();
private:
	void updateNodes();
	void mergeNodes();
	void setupNewNodes();

	std::vector<int> bucketArray;
	Bucket* path[2];
	bool isLeaf = 0, isMerging = 0;
	int mainIterator[2] = { 0,0 };
};
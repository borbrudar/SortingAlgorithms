#pragma once
#include <vector>
#include <cmath>

class Bucket {
public:
	Bucket() = default;
	Bucket(std::vector<int> array);
	~Bucket();
	void init(std::vector<int> array);
	void sortBucket();
	std::vector<int> updateBucket();

	int color = -1;
private:
	void updateNodes();
	void mergeNodes();
	void setupNewNodes();

	std::vector<int> bucketArray;
	Bucket* left = NULL;
	Bucket* right = NULL;
	bool isLeaf = 0, isMerging = 0;
	int firstIterator = 0, secondIterator = 0;
};
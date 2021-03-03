#pragma once
#include <vector>
#include <cmath>

class Bucket {
public:
	Bucket(std::vector<int> array);
	~Bucket();
	void sortBucket();
private:
	void mergeNodes();
	void setupNewNodes();
	std::vector<int> bucketArray;
	Bucket* left = NULL;
	Bucket* right = NULL;
	bool isLeaf = 0;
};
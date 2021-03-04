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
private:
	void updateNodes();
	void mergeNodes();
	void setupNewNodes();
	void pushRemainingElements(bool isLeft, int &itr);

	std::vector<int> bucketArray;
	Bucket* left = NULL;
	Bucket* right = NULL;
	bool isLeaf = 0;
};
#pragma once
#include <vector>
#include <cmath>

template<typename Node>
class BinaryTree {
public:
	BinaryTree() = default;
	
	Node* path[2] = { NULL,NULL };
	int color = -1;

	std::vector<int> dataVector;
};

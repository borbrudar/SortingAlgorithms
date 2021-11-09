#pragma once
#include <vector>
#include <cmath>

template<typename Node>
class BinaryTree {
public:
	BinaryTree() = default;
	int getColor();
private:
	void splitLeft(int midpoint, std::vector<int>& vec);
	void splitRight(int midpoint, std::vector<int>& vec);
protected:
	void splitVectorToNodes(int midpoint);
	void updateNodesBase();

	Node* path[2] = { NULL,NULL };
	int color = -1;
	std::vector<int> dataVector;
};

template<typename Node>
inline void BinaryTree<Node>::splitVectorToNodes(int midpoint)
{
	std::vector<int> leftArr, rightArr;
	splitLeft(midpoint, leftArr);
	splitRight(midpoint, rightArr);
	
	path[0] = new Node(leftArr);
	path[1] = new Node(rightArr);
}

template<typename Node>
inline void BinaryTree<Node>::updateNodesBase()
{
	if (path[0]->color != -1) color = path[0]->color;
	else if (path[1]->color != -1) color = path[0]->dataVector.size() + path[1]->color;

	dataVector.clear();

	for (int i = 0; i < path[0]->dataVector.size(); i++) dataVector.push_back(path[0]->dataVector[i]);
	for (int i = 0; i < path[1]->dataVector.size(); i++) dataVector.push_back(path[1]->dataVector[i]);
}

template<typename Node>
inline int BinaryTree<Node>::getColor()
{
	return color;
}

template<typename Node>
inline void BinaryTree<Node>::splitLeft(int midpoint, std::vector<int> &vec)
{
	vec.resize(midpoint);
	for (int i = 0; i < vec.size(); i++) vec[i] = dataVector[i];
}

template<typename Node>
inline void BinaryTree<Node>::splitRight(int midpoint, std::vector<int>& vec)
{
	vec.resize(dataVector.size() - midpoint);
	for (int i = midpoint, right = 0; i < dataVector.size(); i++, right++) vec[right] = dataVector[i];

}

template<>
inline void BinaryTree<class QuickTree>::splitRight(int midpoint, std::vector<int>& vec)
{
	vec.resize(dataVector.size() - midpoint - 1);
	for (int i = midpoint + 1, right = 0; i < dataVector.size(); i++, right++) vec[right] = dataVector[i];
}

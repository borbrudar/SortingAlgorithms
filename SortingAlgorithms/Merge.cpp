#include "Merge.h"

void Merge::sortArray(std::vector<int>& vec)
{
	// sort array the first time the function is called
	if (!isSorted) {
		vec = splitArray(vec);

		isSorted = true;
	}
	// then replay the solution
	else {
		if (colorItr < stepColorArray.size()) {
			colorArray.push_back(stepColorArray[colorItr]);
			colorItr++;
		}
		if (swapItr < leftSwap.size()) {
			std::iter_swap(vec.begin() + leftSwap[swapItr], vec.begin() + rightSwap[swapItr]);
			swapItr++;
		}
	}
	
}

std::vector<int> Merge::splitArray(std::vector<int> vec)
{
	// dont ask me why, but for some reason it doesnt work in a single statement
	// so here will this useless temp variable stay
	float vecSize = vec.size();
	int midpoint = std::ceilf(vecSize / 2);
	
	if (vecSize == 1) return vec;

	std::vector<int> leftArr;
	leftArr.resize(midpoint);
	for (int i = 0; i < leftArr.size(); i++) leftArr[i] = vec[i];

	std::vector<int> rightArr;
	rightArr.resize(vec.size() - midpoint);
	for (int i = midpoint, right = 0; i < vec.size(); i++, right++) rightArr[right] = vec[i];

	leftArr = splitArray(leftArr);
	rightArr = splitArray(rightArr);
	

	return mergeSort(leftArr, rightArr);
}

std::vector<int> Merge::mergeSort(std::vector<int>& vec1, std::vector<int> &vec2)
{
	std::vector<int> sortedVec;
	firstIterator = 0;
	secondIterator = 0;

	while (true) {
		if (vec1[firstIterator] < vec2[secondIterator]) {
			leftSwap.push_back(vec1[firstIterator]);
			rightSwap.push_back(vec2[secondIterator]);
			stepColorArray.push_back(vec2[secondIterator]);
			updateIterators(sortedVec, vec1, firstIterator);

			if (firstIterator > (vec1.size() - 1)) {
				pushRemainingElements(sortedVec, vec2, secondIterator);
				resetIterators();
				return sortedVec;
			}
		}
		else {
			leftSwap.push_back(vec1[firstIterator]);
			rightSwap.push_back(vec2[secondIterator]);
			stepColorArray.push_back(vec1[firstIterator]);
			updateIterators(sortedVec, vec2, secondIterator);

			if (secondIterator > (vec2.size() - 1)) {
				pushRemainingElements(sortedVec, vec1, firstIterator);
				resetIterators();
				return sortedVec;
			}
		}
	}
}

void Merge::resetIterators()
{
	firstIterator = 0;
	secondIterator = 0;
}

void Merge::updateIterators(std::vector<int>& sortedVec, std::vector<int>& vec, int& itr)
{
	sortedVec.push_back(vec[itr]);
	itr++;
}

void Merge::pushRemainingElements(std::vector<int> &sortedVec, std::vector<int>& vec, int& itr)
{
	for (; itr < vec.size(); itr++)
		sortedVec.push_back(vec[itr]);
}

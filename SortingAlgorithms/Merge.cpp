#include "Merge.h"

void Merge::sortArray(std::vector<int>& vec)
{
	std::vector<int> vec1 = { 4,7,12 };
	std::vector<int> vec2 = { 13,14,15 };
 
	std::vector<int> result = mergeSort(vec1, vec2);
	int b = 0;
}

std::vector<int> Merge::mergeSort(std::vector<int>& vec1, std::vector<int> &vec2)
{
	std::vector<int> sortedVec;

	while (true) {
		if (vec1[firstIterator] < vec2[secondIterator]) {
			updateIterators(sortedVec, vec1, firstIterator);

			if (firstIterator > (vec1.size() - 1)) {
				pushRemainingElements(sortedVec, vec2, secondIterator);
				resetIterators();
				return sortedVec;
			}
		}
		else {
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

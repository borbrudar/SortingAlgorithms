#include "SortingAlgorithm.h"

void SortingAlgorithm::randomize(int vectorSize)
{
	this->vectorSize = vectorSize;
	vec.clear();vec.resize(vectorSize);
	swaps.clear();
	iota(vec.begin(),vec.end(),1);

	std::random_shuffle(vec.begin(),vec.end());
}


bool SortingAlgorithm::verify(){
	for(int i = 1;i < vec.size();i++)
		if(vec[i] < vec[i-1]) return 0;
	return 1;
}
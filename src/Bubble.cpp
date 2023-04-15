#include "Bubble.h"

void Bubble::sortArray()
{
	for(int i = 0;i < vec.size();i++){
		for(int j = i+1;j < vec.size();j++){
			if(vec[i] > vec[j]){
				swaps.push_back({i,vec[j]});
				swaps.push_back({j,vec[i]});
				std::swap(vec[i],vec[j]);
			}
		}
	}

}


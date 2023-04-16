#include "Insertion.h"

void Insertion::sortArray()
{
    for(int i = 1;i < vectorSize;i++){
        int j = i-1;
        while(j >= 0 && vec[j] > vec[j+1]){
            swaps.push_back({j,vec[j+1]});
            swaps.push_back({j+1,vec[j]});
            std::swap(vec[j],vec[j+1]);
            j--;
        }
    }
	
}

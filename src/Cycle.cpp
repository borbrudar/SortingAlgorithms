#include "Cycle.h"

void Cycle::sortArray()
{
    for(int i = 0;i < vectorSize;i++){
        while(vec[i] != i+1){
            swaps.push_back({i,vec[i]-1});
            std::swap(vec[vec[i]-1],vec[i]);
        }
    }
}

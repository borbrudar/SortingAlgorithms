#include "Cycle.h"

void Cycle::sortArray()
{
    for(int i = 0;i < vectorSize;i++){
        while(vec[i] != i+1){
            swaps.push_back({i,vec[vec[i]-1]});
            swaps.push_back({vec[i]-1,vec[i]});
            std::swap(vec[vec[i]-1],vec[i]);
        }
    }
}

#include "Selection.h"

void Selection::sortArray()
{   
    for(int nxt =1;nxt <= vectorSize;nxt++){
        for(int i  = 0; i < vectorSize;i++){
            if(vec[i] == nxt){
                if(i == nxt-1) break;
                swaps.push_back({i,vec[nxt-1]});
                swaps.push_back({nxt-1,vec[i]});
                std::swap(vec[i],vec[nxt-1]);
                break;
            }
        }
    }
}


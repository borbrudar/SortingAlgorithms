#include "Merge.h"

void Merge::sortArray()
{
    split(0,vectorSize-1);
}

void Merge::split(int l,int r){
    if(l == r) return;
    int mid = (l+r)/2;
    split(l,mid);
    split(mid+1,r);

    auto t1 = std::vector<int>(vec.begin()+l,vec.begin()+mid+1);
    auto t2 = std::vector<int>(vec.begin()+mid+1,vec.begin()+r+1);
    //merge together
    int i = 0,j = 0, cur=l,ex = 0;
    while(i < t1.size() && j < t2.size()){
        if(t1[i] < t2[j]) swaps.push_back({cur,t1[i]}),vec[cur++] = t1[i++];
        else swaps.push_back({cur,t2[j]}),vec[cur++] = t2[j++];
    }
    while(i < t1.size()) swaps.push_back({cur,t1[i]}),vec[cur++] = t1[i++];
    while(j < t2.size()) swaps.push_back({cur,t2[j]}),vec[cur++] = t2[j++];
} 

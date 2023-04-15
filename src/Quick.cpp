#include "Quick.h"

void Quick::sortArray()
{
    sort(0,vectorSize-1);
}

void Quick::sort(int l, int r)
{
    if(l == r) return;
    int pivot = vec[r];

    int i=l,j = r-1;
    while(i <= j){
        if(vec[i] < pivot) {i++;continue;}
        if(vec[j] > pivot) {j--;continue;}
        swaps.push_back({i,vec[j]});
        swaps.push_back({j,vec[i]});
        std::swap(vec[i],vec[j]);
    }

    if(vec[i] > pivot){
        swaps.push_back({i,pivot});
        swaps.push_back({r,vec[i]});
        std::swap(vec[i],vec[r]);
        sort(l,i);
        sort(i+1,r);
    }else sort(l,r-1);
}

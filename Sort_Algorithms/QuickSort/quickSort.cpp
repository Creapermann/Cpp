#include "quickSort.hpp"


quickSort::quickSort(TIntVec a, int n){
    mainSort(a, 0, n - 1);
    quickSort::printResVec(a, n);
}

void quickSort::mainSort(TIntVec a, int s, int e){

    if(s < e){
        int pIndex = partitioning(a, s, e);
        mainSort(a, 0, pIndex);
        mainSort(a, pIndex + 1, e);
    }
}

int quickSort::partitioning(TIntVec a, int s, int e){
    int pIndex = s;
    int pivot = a[e];

    for(int i = s; i <= e - 1; i++){
        if(a[i] <= pivot){
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = a[e];
    a[e] = a[pIndex];
    a[pIndex] = temp;
    
    return pIndex;
}

void quickSort::printResVec(TIntVec a, int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}
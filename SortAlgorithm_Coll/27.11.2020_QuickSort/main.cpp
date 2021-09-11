#include <iostream>

#include "quickSort.cpp"

int main(){

    std::vector<int> a = { 3, 19, 32 , 7, 21, 19 };
    
    int n = a.size();

    auto obj1 = quickSort(a, n);

    return 0;
}
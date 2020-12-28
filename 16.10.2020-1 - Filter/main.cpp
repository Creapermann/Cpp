#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include "filterMotives.cpp"


int main()
{
    //Vars
    auto allowedAmount = 2;
    std::vector<int> mainVec = { 20, 21,20,21, 32, 47, 20, 32, 20, 21, 32 };

    auto filterNumbers = filterMotives(mainVec, allowedAmount);    //creates a new object of "filterMotives"
}


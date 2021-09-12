#pragma once

#include <vector>

using TIntVec = std::vector<int>;

class GetPrimes{
public:
    GetPrimes();
    TIntVec findAllPrimes(const int);
};

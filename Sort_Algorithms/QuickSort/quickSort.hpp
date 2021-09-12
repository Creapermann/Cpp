#include <iostream>
#include <vector>

using TIntVec = std::vector<int>;


class quickSort
{
public:
    quickSort(TIntVec, int);

private:
    void mainSort(TIntVec, int, int);
    int partitioning(TIntVec, int, int);
    void printResVec(TIntVec, int);
};  
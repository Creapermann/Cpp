#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>


struct histogram {                                       //creates the histogram stuct

    int cnt;
    int elem;
};

using vectorHistogram = std::vector<histogram>;        //creates a new type "vectorHistogram"



class filterMotives {
public:
    filterMotives(std::vector<int> mainVec, int allowedAmount);

private:
    //Methods
    void printOutputVec(std::vector<int> mainVec);        //prints out the given vector
    std::vector<int> removeMotives(int howManyTooMuch, const std::vector<int>& mainVec, int motive);                            //!Gets called by "sortUnAllowedElements"! removes the given elements
    std::vector<int> sortUnAllowedElements(const std::vector<int>& mainVec, vectorHistogram& HistogramVc, int allowedAmount);    /*sorts the Elements with duplicates above "allowedAmount" 
                                                                                                                                   and calls "removeElements" for them*/
    vectorHistogram initHistogramVector(std::vector<int>& mainVec, std::vector<int>& noDoubleValuesVec);                         //inits the Histogram vector
};
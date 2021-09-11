#include "filterMotives.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>


//Default-Constructor
filterMotives::filterMotives(std::vector<int> mainVec, int allowedAmount) {

    std::unordered_set<int> noDoubleValuesUSet(mainVec.begin(), mainVec.end());
    std::vector<int> noDoubleValuesVec(noDoubleValuesUSet.begin(), noDoubleValuesUSet.end());

    auto HistogramVc = initHistogramVector(mainVec, noDoubleValuesVec);
    auto resVec = sortUnAllowedElements(mainVec, HistogramVc, allowedAmount);
    printOutputVec(resVec);
}


//Methods
void filterMotives::printOutputVec(std::vector<int> mainVec) {
    for (auto i : mainVec) {
        std::cout << i << std::endl;
    }
}



std::vector<int> filterMotives::removeMotives(int howManyTooMuch, const std::vector<int>& mainVec, int motive) {
    auto res = mainVec;
    for (auto i = 0; i < howManyTooMuch; i++) {
        auto it = std::find(res.rbegin(), res.rend(), motive);      //finds a elements in the vector (from the end to the begin -> reversed) and lets an reversed It point to it
        res.erase(std::next(it).base());                            //converts the reversed It to a normal It amd deletes the element where the It points to
    }

    return  res;
}


std::vector<int> filterMotives::sortUnAllowedElements(const std::vector<int>& mainVec, vectorHistogram& HistogramVc, int allowedAmount) {

    auto res = mainVec;

    auto it = std::partition(HistogramVc.begin(), HistogramVc.end(), [allowedAmount = allowedAmount](auto& o) -> bool {   //sorts out the elements which counts are above "allowedAmount"
        return o.cnt > allowedAmount;
        });

    auto dist = static_cast<size_t>(std::distance(HistogramVc.begin(), it));
    for (auto i = 0u; i < dist; i++) {
        int howManyTooMuch = HistogramVc[i].cnt - allowedAmount;              //gets the amount of duplicates which arent allowed to exist
        res = removeMotives(howManyTooMuch, res, HistogramVc[i].elem);       //removes the duplicates which arent allowed to exist
    }
    return res;
}



vectorHistogram filterMotives::initHistogramVector(std::vector<int>& mainVec, std::vector<int>& noDoubleValuesVec) {    //inits the Histogram

    auto HistogramVc = vectorHistogram(noDoubleValuesVec.size());           //Inits a vector of the type "vectorHistogram" and the size of "noDoubleValuesVec"

    std::transform(noDoubleValuesVec.begin(), noDoubleValuesVec.end(), HistogramVc.begin(), [mainVec = mainVec](auto& element) -> histogram {
        auto temp = histogram();                                                      //creates a object of type histogram
        temp.elem = element;                                                          //inits the vars of histogram
        temp.cnt = std::count(mainVec.begin(), mainVec.end(), element);               //inits the vars of histogram

        return temp;                                                                  //adds this new object of type histogram with inited vars to "HistogramVc"
        });

    return HistogramVc;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>


int retResult(std::string &inputNumString) {

    auto Result = 10;

    while (std::to_string(Result).size() != 1)
    {
        std::vector<int> seppedInts;
        for (auto i = 0; i < inputNumString.size(); i++) {
            auto k = inputNumString[i];
            auto j = k - 48;                                                                  //-48 Ascci tabelle -> 0
            seppedInts.push_back(j);
        }

        Result = std::accumulate(seppedInts.begin(), seppedInts.end(), 0);
        inputNumString = std::to_string(Result);
    }

    return Result;
}

std::string convIntToString(const int &inputNum) {
    return std::to_string(inputNum);
}

int getInput() {
    auto i = 0;
    std::cin >> i;

    return i;
}

int main()
{
    auto inputNum = getInput();
    auto inputNumString = convIntToString(inputNum);
    std::cout << retResult(inputNumString) << std::endl;


    int eND;
    std::cin >> eND;
    return 0;
}

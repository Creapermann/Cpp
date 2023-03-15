#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

void clearConsole() {
    system("CLS");
}

void printVector(const std::vector<std::string> &v) {
    for (auto s : v) {
        std::cout << s << std::endl;
    }
    if (v.size() == 0) {
        std::cout << "No matches found" << std::endl;
    }
}

std::vector<std::string> sortVector(std::vector<std::string> &v) {
    std::sort(v.begin(), v.end(), [](const std::string& s1, const std::string& s2) {return s1 < s2; });

    return v;
}

std::vector<std::string> retSubstringsAsVector(std::vector<std::string> n1Vec, std::vector<std::string> n2Vec) {
    

    std::set<std::string> SubstringSet;

    for (auto i = 0; i < n2Vec.size(); i++) {
        for (auto k = 0; k < n1Vec.size(); k++) {
            if (n2Vec[i].find(n1Vec[k]) != std::string::npos){
                SubstringSet.insert(n1Vec[k]);
            }
        }
    }

    std::vector<std::string> SubstringVec(SubstringSet.begin(), SubstringSet.end());

    return SubstringVec;
}

void getInput(std::vector<std::string> &firstInputVec, std::vector<std::string> &secoundInputVec) {

    std::cout << "Write how many sub-strings do you want to write into your first vector?" << std::endl;
    
    auto amountOfStringInFirst = 1;
    std::cin >> amountOfStringInFirst;
    clearConsole();
    std::cout << "Give in your sub-strings sepperated by a 'ENTER'" << std::endl;
    
    for (auto i = 0; i < amountOfStringInFirst; i++) {
        std::string a;
        std::cin >> a;
        firstInputVec.push_back(a);
        clearConsole();
    }

    std::cout << "Write how many strings do you want to write into your secound vector?" << std::endl;

    auto amountOfStringInSecound = 1;
    std::cin >> amountOfStringInSecound;
    clearConsole();
    std::cout << "Give in your strings sepperated by a 'ENTER'" << std::endl;

    for (int i = 0; i < amountOfStringInSecound; i++) {
        std::string a;
        std::cin >> a;
        secoundInputVec.push_back(a);
        clearConsole();
    }
}


int main()
{
    std::vector<std::string> vec1, vec2;
    getInput(vec1, vec2);
    auto substringVec = retSubstringsAsVector(vec1, vec2);
    auto mainVec = sortVector(substringVec);
    printVector(mainVec);


    int eND;
    std::cin >> eND;
    return 0;
}


#include <iostream>
#include <string>
#include <vector>


int retAmountOfErrors(const std::string &inputString) {

    auto amountOfErrors = 0;

    std::vector<char> stringVec(inputString.begin(), inputString.end());

    for (auto i = 0; i < stringVec.size(); i++) {
        switch (stringVec[i]) {
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'g':
            break;
        case 'h':
            break;
        case 'i':
            break;
        case 'j':
            break;
        case 'k':
            break;
        case 'l':
            break;
        case 'm':
            break;
        default:
            amountOfErrors++;
        }
    }

    return amountOfErrors;
}


int main(){
    
    std::string inputString;
    std::cin >> inputString;

    auto amountOfErrors = retAmountOfErrors(inputString);
    std::cout << "error_printer(s) => '" << std::to_string(amountOfErrors) << "/" << inputString.length() << "'";

    int eND;
    std::cin >> eND;
    return 0;
}

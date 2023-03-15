#include <iostream>
#include <vector>

void clearCons() {
    system("CLS");
}



void printOut(const std::vector<std::string> &namesVec, const int &namesAmount) {
    
    switch (namesAmount) {
    case 1:
        std::cout << namesVec[0] << " likes this" << std::endl;
        break;
    case 2:
        std::cout << namesVec[0] << " and " << namesVec[1] << " like this" << std::endl;
        break;
    case 3:
        std::cout << namesVec[0] << ", " << namesVec[1] << " and " << namesVec[2] << " like this" << std::endl;
        break;
    default:
        std::cout << namesVec[0] << ", " << namesVec[1] << " and " << namesAmount - 2 << " other(s)" << " like(s) this " << std::endl;
    }
}

std::vector<std::string> retNamesVec(int &namesAmount) {
    std::vector<std::string> namesVec;

    auto nameLoopIsOver = false;
    while (nameLoopIsOver != true) {
        std::cout << "Type in a name (write 'stop!' when you finished)" << std::endl;
        std::string name;
        std::cin >> name;
        if (name != "stop!") {
            namesVec.push_back(name);
            namesAmount++;
        }
        else {
            nameLoopIsOver = true;
        }
        clearCons();
    }

    return namesVec;
}

int main()
{
    auto namesAmount = 0;
    auto namesVec = retNamesVec(namesAmount);
    printOut(namesVec, namesAmount);

    int eND;
    std::cin >> eND;
    return 0;
}

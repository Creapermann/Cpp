#include <iostream>

#include "bubbleSort.hpp"
#include <gtest/gtest.h>

int main() {


    TIntVec mainVec = { 7, 1, 29, 1, 6, 7, 3, 5, 4, 0, 8 };

     bubbleSort bs(mainVec);              //creates new object of Type "bubbleSort"

	return 0;
}

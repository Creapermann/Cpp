#include <vector>

#include "gtest/gtest.h"
#include "../../include/bubbleSort.hpp"

using TIntVec = std::vector<int>;

TEST(AdditionTest,twoValues){

    const TIntVec x = { 1, 2, 4, 6, 1, 3, 9, 20};

    EXPECT_EQ(x, sortVec(x));
}

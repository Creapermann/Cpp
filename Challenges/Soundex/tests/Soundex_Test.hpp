#include <string>

#include "gtest/gtest.h"

#include "Soundex.hpp"


class Soundex_Test : public testing::Test
{
public:
    Soundex soundex;
};


TEST_F(Soundex_Test, EmptyInput)
{
    EXPECT_EQ(soundex.encode(""), "0000");
}

TEST_F(Soundex_Test, TooMuchInput)
{
    EXPECT_EQ(soundex.encode("Fzrxlmnkqpu"),  "F262");
    EXPECT_EQ(soundex.encode("aAAooppajsea"), "A120");    
}

TEST_F(Soundex_Test, WithNumbers)
{
    EXPECT_THROW(soundex.encode("F129k"), std::invalid_argument);
    EXPECT_THROW(soundex.encode("1101"),  std::invalid_argument);
}

TEST_F(Soundex_Test, WithSpecialCharacters)
{
    EXPECT_THROW(soundex.encode("F*as"), std::invalid_argument);
    EXPECT_THROW(soundex.encode("1101"), std::invalid_argument);
}

TEST_F(Soundex_Test, CaseSensitivity)
{
    EXPECT_EQ(soundex.encode("lrmx"), "L652");
    EXPECT_EQ(soundex.encode("Lrmx"), "L652");
}

TEST_F(Soundex_Test, NormalEncoding1)
{
    EXPECT_EQ(soundex.encode("lazarescu"), "L262");
    EXPECT_EQ(soundex.encode("Rupert"),    "R163");
    EXPECT_EQ(soundex.encode("Robin"),     "R150");
}


TEST_F(Soundex_Test, NormalEncoding2)
{
    EXPECT_EQ(soundex.encode("Yaramel"),  "Y654");
    EXPECT_EQ(soundex.encode("Sam"),     "S500");
    EXPECT_EQ(soundex.encode("Nicolai"),  "N240");
}
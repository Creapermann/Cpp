#include "pch.h"
#include "../Even_Fbonacci_Nmbers/fibonacci.cpp"

//getFibsTo() function tests
TEST(getFibsTo_Test, test1) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> temp = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	EXPECT_EQ(fib.getFibsTo(100), temp);
}
TEST(getFibsTo_Test, test2) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> temp = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 };
	EXPECT_EQ(fib.getFibsTo(500), temp);
}
TEST(getFibsTo_Test, test3) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> temp = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987 };
	EXPECT_EQ(fib.getFibsTo(1000), temp);
}

//filterAllEvenNumbers() function tests
TEST(filterAllEvenNumbers_Test, test1) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<long long> expectedOutCome = { 2, 4, 6, 8, 10 };

	EXPECT_EQ(fib.filterAllEvenNumbers(toTest), expectedOutCome);
}
TEST(filterAllEvenNumbers_Test, test2) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 10, 100, 1000, 10000 };
	std::vector<long long> expectedOutCome = { 10, 100, 1000, 10000 };

	EXPECT_EQ(fib.filterAllEvenNumbers(toTest), expectedOutCome);
}
TEST(filterAllEvenNumbers_Test, test3) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 12, 19, 1112, 443, 1921, 2000 };
	std::vector<long long> expectedOutCome = { 12, 1112, 2000 };

	EXPECT_EQ(fib.filterAllEvenNumbers(toTest), expectedOutCome);
}
TEST(filterAllEvenNumbers_Test, test4) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 21, 13, 15, 2, 5 };
	std::vector<long long> expectedOutCome = { 2 };

	EXPECT_EQ(fib.filterAllEvenNumbers(toTest), expectedOutCome);
}
TEST(filterAllEvenNumbers_Test, test5) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 20001, 18282, 2718, 198283, 1028982, 882712, 27361253 };
	std::vector<long long> expectedOutCome = { 18282, 2718, 1028982, 882712, };

	EXPECT_EQ(fib.filterAllEvenNumbers(toTest), expectedOutCome);
}

//sumVec() function tests
TEST(sumVec_Test, test1) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 1, 2, 3, 4, 5 };
	long long expecteOutCome = 15;

	EXPECT_EQ(fib.sumVec(toTest), expecteOutCome);
}
TEST(sumVec_Test, test2) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 21, 39, 40, 51 };
	long long expecteOutCome = 151;

	EXPECT_EQ(fib.sumVec(toTest), expecteOutCome);
}
TEST(sumVec_Test, test3) {
	Fibonacci fib = Fibonacci();
	std::vector<long long> toTest = { 0, 0, 0, 0 };
	long long expecteOutCome = 0;

	EXPECT_EQ(fib.sumVec(toTest), expecteOutCome);
}
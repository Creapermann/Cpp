#include "pch.h"
#include "../../Linked-List/Linked-List/src/LinkedList.hpp"

TEST(Insertion, insert) {
	LinkedList<int> ll;

	ll.insert(0, 1);
	std::vector<int> a1{ 1 };
	EXPECT_EQ(ll.toVector(), a1);

	ll.insert(0, -1);
	std::vector<int> a2{ -1, 1 };
	EXPECT_EQ(ll.toVector(), a2);

	ll.insert(2, 9);
	std::vector<int> a3{ -1, 1, 9 };
	EXPECT_EQ(ll.toVector(), a3);

	ll.insert(2, 3);
	std::vector<int> a4{ -1, 1, 3, 9 };
	EXPECT_EQ(ll.toVector(), a4);

	ll.insert(0, 1);
	std::vector<int> a5{ 1, -1, 1, 3, 9 };
	EXPECT_EQ(ll.toVector(), a5);

	ll.insert(2, 7);
	std::vector<int> a6{ 1, -1, 7, 1, 3, 9 };
	EXPECT_EQ(ll.toVector(), a6);
}

TEST(Insertion, pushback)
{
	LinkedList<int> ll;

	ll.push_back(0);
	std::vector<int> a1{ 0 };
	EXPECT_EQ(ll.toVector(), a1);

	ll.push_back(1);
	std::vector<int> a2{ 0, 1 };
	EXPECT_EQ(ll.toVector(), a2);

	ll.push_back(3);
	std::vector<int> a3{ 0, 1, 3 };
	EXPECT_EQ(ll.toVector(), a3);

	ll.push_back(-9);
	std::vector<int> a4{ 0, 1, 3, -9 };
	EXPECT_EQ(ll.toVector(), a4);

	ll.push_back(11);
	std::vector<int> a5{ 0, 1, 3, -9, 11 };
	EXPECT_EQ(ll.toVector(), a5);

	ll.push_back(-99999);
	std::vector<int> a6{ 0, 1, 3, -9, 11, -99999 };
	EXPECT_EQ(ll.toVector(), a6);
}

TEST(Insertion, pushfront)
{
	LinkedList<int> ll;

	ll.push_front(3);
	std::vector<int> a1{ 3 };
	EXPECT_EQ(ll.toVector(), a1);

	ll.push_front(-9);
	std::vector<int> a2{ -9, 3 };
	EXPECT_EQ(ll.toVector(), a2);

	ll.push_front(1);
	std::vector<int> a3{ 1, -9, 3 };
	EXPECT_EQ(ll.toVector(), a3);

	ll.push_front(918);
	std::vector<int> a4{ 918, 1, -9, 3 };
	EXPECT_EQ(ll.toVector(), a4);

	ll.push_front(-192);
	std::vector<int> a5{ -192, 918, 1, -9, 3 };
	EXPECT_EQ(ll.toVector(), a5);

	ll.push_front(-1);
	std::vector<int> a6{ -1, -192, 918, 1, -9, 3 };
	EXPECT_EQ(ll.toVector(), a6);
}

TEST(Insertion, mix)
{
	LinkedList<int> ll;

	ll.insert(0, 1);
	std::vector<int> a1{ 1 };
	EXPECT_EQ(ll.toVector(), a1);

	ll.push_front(9);
	std::vector<int> a2{ 9, 1 };
	EXPECT_EQ(ll.toVector(), a2);

	ll.push_back(2);
	std::vector<int> a3{ 9, 1, 2 };
	EXPECT_EQ(ll.toVector(), a3);

	ll.insert(0, 1);
	std::vector<int> a4{ 1, 9, 1, 2 };
	EXPECT_EQ(ll.toVector(), a4);

	ll.push_front(-99);
	std::vector<int> a5{ -99, 1, 9, 1, 2 };
	EXPECT_EQ(ll.toVector(), a5);

	ll.push_back(-99);
	std::vector<int> a6{ -99, 1, 9, 1, 2, -99 };
	EXPECT_EQ(ll.toVector(), a6);
}

TEST(Deletion, mix)
{
	LinkedList<int> ll;
	ll.push_front(9);
	ll.insert(0, 1);
	ll.insert(0, 1);
	ll.push_back(-99);
	ll.push_front(-99);
	ll.push_back(2);
	ll.push_back(9);
	ll.insert(3, 5);
	ll.push_back(1991);

	// -99,1,1,5,9,-99,2,9,1991
	
	ll.pop_back();
	std::vector<int> a1{ -99,1,1,5,9,-99,2,9 };
	EXPECT_EQ(ll.toVector(), a1);

	ll.pop_front();
	std::vector<int> a2{ 1,1,5,9,-99,2,9 };
	EXPECT_EQ(ll.toVector(), a2);

	ll.remove(2);
	std::vector<int> a3{ 1,1,9,-99,2,9 };
	EXPECT_EQ(ll.toVector(), a3);

	ll.remove(0);
	std::vector<int> a4{ 1,9,-99,2,9 };
	EXPECT_EQ(ll.toVector(), a4);

	ll.remove(4);
	std::vector<int> a5{ 1,9,-99,2 };
	EXPECT_EQ(ll.toVector(), a5);

	ll.remove(2);
	std::vector<int> a6{ 1,9,2 };
	EXPECT_EQ(ll.toVector(), a6);

	ll.pop_front();
	std::vector<int> a7{ 9,2 };
	EXPECT_EQ(ll.toVector(), a7);

	ll.pop_back();
	std::vector<int> a8{ 9 };
	EXPECT_EQ(ll.toVector(), a8);

	ll.pop_back();
	std::vector<int> a9{ };
	EXPECT_EQ(ll.toVector(), a9);

	ll.pop_front();
	std::vector<int> a10{ };
	EXPECT_EQ(ll.toVector(), a10);

	ll.pop_back();
	std::vector<int> a11{ };
	EXPECT_EQ(ll.toVector(), a11);
}
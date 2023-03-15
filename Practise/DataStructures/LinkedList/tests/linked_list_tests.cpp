#include <gtest/gtest.h>
#include "LinkedList.hpp"


TEST(ALinkedLists, SucceedsDefaultConstruction)
{
    LinkedList<int> ll;

    EXPECT_EQ(0, ll.size());
}

TEST(ALinkedLists, SucceedConstructionWithInitializerList)
{
    LinkedList<int> ll{ 1,2,3,4,5 };

    EXPECT_EQ(5, ll.size());
}

TEST(ALinkedLists, SucceedsPushbacks)
{
    LinkedList<int> ll;
    ll.push_back(4);
    EXPECT_EQ(1, ll.size());
    EXPECT_EQ(4, ll[0].data());

    ll.push_back(2);
    EXPECT_EQ(2, ll.size());
    EXPECT_EQ(2, ll[1].data());
}

TEST(ALinkedLists, SucceedsPopbacks)
{
    LinkedList<int> ll( { 2,3,4 } );
    ll.pop_back();
    EXPECT_EQ(2, ll.size());

    ll.pop_back();
    EXPECT_EQ(1, ll.size());

    ll.pop_back();
    EXPECT_EQ(0, ll.size());

}

TEST(Node, SucceedsImplicitConversionToT)
{
    LinkedList<int> ll( { 2,3,4 } );
    EXPECT_EQ(2, ll[0]);
}

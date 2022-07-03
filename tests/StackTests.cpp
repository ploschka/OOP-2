#include "Stack.h"
#include "gtest/gtest.h"

TEST(StackTest, PushPopTest)
{
    Stack<int> s;
    s.push(5);
    s.push(6);

    EXPECT_EQ(s.pop(), 6);
    EXPECT_EQ(s.pop(), 5);

    s.push(7);
    EXPECT_EQ(s.pop(), 7);
}

TEST(StackTest, EmptyTest)
{
    Stack<int> s;
    EXPECT_TRUE(s.is_empty());

    s.push(6);
    EXPECT_FALSE(s.is_empty());

    s.pop();
    EXPECT_TRUE(s.is_empty());
}
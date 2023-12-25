#include "MyStack.h"
#include <gtest.h>
#include "MyStack.cpp"


TEST(StackTest, IsEmptyInitially)
{
    MyStack<int> stack;
    EXPECT_TRUE(stack.IsEmpty());
    EXPECT_EQ(0, stack.GetSize());
}
TEST(StackTest, IsFullReturnsTrueWhenStackIsFull)
{
    MyStack<int> stack(2);
    stack.Push(10);
    stack.Push(20);
    EXPECT_TRUE(stack.IsFull());
    EXPECT_EQ(2, stack.GetSize());
}
TEST(StackTest, IsFullReturnsFalseWhenStackIsNotFull)
{
    MyStack<int> stack(2);
    stack.Push(10);
    EXPECT_FALSE(stack.IsFull());
    EXPECT_EQ(2, stack.GetSize());
}







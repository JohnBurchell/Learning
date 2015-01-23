#include "gtest/gtest.h"
#include "stack.h"

#include <limits>

using namespace std;

class StackTests : public ::testing::Test {

protected:
	Stack<int> stack;
};

TEST_F(StackTests, IsEmptyInitially)
{
	ASSERT_TRUE(stack.size() == 0);
	ASSERT_TRUE(stack.empty());
}

TEST_F(StackTests, PeekPop)
{
	stack.push(1);
	int top = stack.peek();
	int popped = stack.pop();
	ASSERT_TRUE(top == popped);
	ASSERT_TRUE(stack.empty());
}

TEST_F(StackTests, Peek)
{
	stack.push(1);
	ASSERT_TRUE(1 == stack.peek());
}

TEST_F(StackTests, Pop)
{
	stack.push(1);
	ASSERT_FALSE(stack.empty());
	ASSERT_TRUE(stack.peek() == 1);
	ASSERT_TRUE(stack.pop() == 1);
	ASSERT_TRUE(stack.empty());
}

TEST_F(StackTests, Push_One)
{
	ASSERT_TRUE(stack.empty());
	stack.push(1);
	ASSERT_TRUE(stack.size() == 1);
}

TEST_F(StackTests, Push_Ten)
{
	ASSERT_TRUE(stack.empty());
	for(int i = 0; i < 10; ++i)
	{
		stack.push(i);
	}
	ASSERT_TRUE(stack.size() == 10);
}

TEST_F(StackTests, PushPopRandom)
{
	ASSERT_TRUE(stack.empty());

	int pushCount = 10;
	int popCount = 5;

	for(int i = 0; i < pushCount; ++i)
	{
		stack.push(i);
	}

	for(int i = 0; i < popCount; ++i)
	{
		stack.pop();
	}

	ASSERT_TRUE(stack.size() == pushCount - popCount);
}

#include "gtest/gtest.h"
#include "linkedlist.h"

#include <limits>

using namespace std;

class LinkedListTests : public ::testing::Test {

protected:
	LinkedList<int> list;
};

TEST_F(LinkedListTests, addOne)
{
	list.insert(1);
	ASSERT_TRUE(list.head->key == 1);
}

TEST_F(LinkedListTests, addMultiple)
{
	int count = 10;

	for(int i = 0; i < count; ++i)
	{
		list.insert(i);
	}

	auto current = list.head;

	for(int i = count - 1; i >= 0; --i)
	{
		ASSERT_TRUE(i == current->key);
		current = current->next;
	}
}

TEST_F(LinkedListTests, search)
{
	int count = 10;

	for(int i = 0; i < count; ++i)
	{
		list.insert(i);
	}

	auto element = list.search(5);
	ASSERT_TRUE(element);

	element = list.search(100000);
	ASSERT_FALSE(element);
}

TEST_F(LinkedListTests, removeOne)
{
	int count = 10;

	for(int i = 0; i < count; ++i)
	{
		list.insert(i);
	}

	auto element = list.search(6);
	list.delete_node(element);
	element = list.search(6);
	ASSERT_FALSE(element);
	ASSERT_TRUE(list.search(5));
	ASSERT_TRUE(list.search(7));
}

TEST_F(LinkedListTests, removeAll)
{
	list.insert(1);
}


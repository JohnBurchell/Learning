#include "gtest/gtest.h"
#include "queue.h"

#include <limits>

using namespace std;

class QueueTests : public ::testing::Test {

protected:
	Queue<int> queue;
};

TEST_F(QueueTests, PassingTest)
{
	//TODO
}

TEST_F(QueueTests, EnqueueDequeue)
{
	queue.enqueue(1);
	//ASSERT_TRUE(queue.dequeue() == 1);
}

TEST_F(QueueTests, Enqueue_Multiple)
{
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	ASSERT_TRUE(queue.dequeue() == 1);
}



TEST_F(QueueTests, EnqueueDequeueFail)
{
}

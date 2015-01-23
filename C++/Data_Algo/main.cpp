#include <iostream>
#include <gtest/gtest.h>
#include "queueTests.h"
#include "stackTests.h"
#include "linkedListTests.h"

using namespace std;

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
  	auto result = RUN_ALL_TESTS();
	return 0;
}
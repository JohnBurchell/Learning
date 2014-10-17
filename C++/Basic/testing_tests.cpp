#include <unit++.h>
#include <string>

using namespace unitpp;
using namespace std;

namespace{
	class MyTest : public suite
	{
		void testEmptyString()
		{
			std::string john;
			//Order - Param / Expected / Actual
			assert_eq("length check", static_cast<unsigned int>(0), john.length());
			assert_eq("content check", "", john);
		}

		public:
			MyTest() : suite("MyFirstTestSuite")
			{
				add("EmptyString", testcase(this, "TestEmptyString", &MyTest::testEmptyString));
				suite::main().add("MyTestSuite", this);
			}

	};

	//Not sure what the intention here was origanlly, he had no type declared!
	MyTest* theTest = new MyTest();
}



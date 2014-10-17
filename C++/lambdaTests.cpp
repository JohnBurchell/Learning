#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Test
{
	public:
		Test(int input, bool boolean) :
			foo{input},
			bar{boolean}
			{};
		~Test() {};

		inline bool hasCollided() { return bar; };

		friend std::ostream& operator <<(std::ostream& os, Test& t);


	private:
		int foo;
		bool bar;
};

std::ostream& operator <<(std::ostream& os, Test& t)
{
	std::cout << "Value of : " << t.foo << " With boolean " << t.bar << std::endl;
}

int main()
{
	std::vector < Test > testVec {{1, true}, {2, false}, {3, false}, {4, true}, {5, true}};

	for(auto& x : testVec) {
		std::cout << x;
	}

	std::vector<Test> t2;

	t2.emplace_back(Test{1, true});

	auto tester = [=](Test& a){ return a.hasCollided(); };

	std::cout << "---------" << std::endl;

	testVec.erase(std::remove_if(std::begin(testVec), std::end(testVec), tester), std::end(testVec));

	for(auto& x : testVec) {
		std::cout << x;
	}
}
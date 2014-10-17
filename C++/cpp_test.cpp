#include <iostream>
#include <vector>
#include <string>

int main()
{

	//std::vector<std::string*> pStrings;
	std::vector<std::string> strings;

	for(int i = 0; i < 5; ++i)
	{
		//pStrings.emplace_back(new std::string{"Test"});
		strings.emplace_back("Test");
	}

	// for(auto& x : pStrings)
	// {
	// 	std::cout << *x << std::endl;
	// }

	for(auto& x : strings)
	{
		std::cout << x << std::endl;
	}
}
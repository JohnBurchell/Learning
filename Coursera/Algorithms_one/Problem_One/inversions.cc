#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int count(int& a, int len)
{
	if(len == 1)
	{
		return 0;
	}

	auto x = count(a, len / 2);
	auto y = count(a, len / 2);
	//
}

std::vector<int> read_file()
{
	fstream input{};
	input.open("test.txt");

	string input_string;
	while(getline(input, input_string))
	{
		cout << input_string << endl;
	}

	input.close();
}

int inversions(int& one, int& two)
{
	return 0;
}

int main()
{
	read_file();

	return 0;
}
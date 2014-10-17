#include <random>
#include <iostream>
#include <functional>

class Rand_int {
public:
	Rand_int(int low, int high) :dist(low,high) {}
	int operator()() { return dist(re); }
private:
	std::default_random_engine re;
	std::uniform_int_distribution<> dist;
};

int main() {


	Rand_int rnd {0,30};

	std::vector<int> histogram(31);
	for(int i = 0; i!=200; ++i)
		++histogram[rnd()];

	for(int i = 0; i!=histogram.size(); ++i){
		std::cout << i << '\t';
		for(int j=0; j!=histogram[i]; ++j) std::cout << '*';
		std::cout<< std::endl;
	}

	//Comparison of randoms.

	auto ndist = std::bind(std::normal_distribution<>{0,30}, std::default_random_engine{});

	std::vector<int> histogram2(31);

	for(int i = 0; i!=200; ++i)
		++histogram2[rnd()];

	for(int i = 0; i!=histogram2.size(); ++i){
		std::cout << i << '\t';
		for(int j=0; j!=histogram2[i]; ++j) std::cout << '*';
		std::cout<< std::endl;
	}
	
}
#include <chrono>
#include <iostream>

using namespace std::chrono;

int main() {

	int result = 1;
	std::cout << "Starting timer of loop!" << std::endl;

	auto t1 = high_resolution_clock::now();

	for(int i = 1; i < 1000000000; i++) {
		result += i;
	}

	auto t2 = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds>(t2-t1).count() << " MS passed\n";
	std::cout << result << std::endl;


}
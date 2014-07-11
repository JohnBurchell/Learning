/*On my current version of Ubuntu 13.10 i had to run this command
  To get it to compile:
  g++ -Wl,--no-as-needed -std=c++11 -pthread main.cpp -o main.out
  Try this if yours doesn't work again! -- Someone suggested to try clang isntead!
  */
#include <chrono>
#include <thread>
#include <iostream>

  using namespace std::chrono;

void threads();
void f1();
void f2();

int main() 
{
	threads();
}

void threads() 
{
	std::cout << "Starting" << std::endl;
	std::thread thread1{f1};
	std::thread thread2{f2};

	thread1.join();
	thread2.join();

}

void f1() 
{	
	while(true) {
		std::cout << "Hello," << std::endl;
		std::this_thread::sleep_for(seconds{1});
	}
}


void f2()
{
	while(true) {
		std::cout << "World!" << std::endl;
		std::this_thread::sleep_for(seconds{1});
	}
}
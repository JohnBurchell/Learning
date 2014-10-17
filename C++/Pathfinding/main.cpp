#include <iostream>

#include "graphics.h"
#include "graph.h"

class Graphics;

auto f(double) -> int;

int main()
{
	Graphics graphics;

	std::cout << "Hello from Nav" << std::endl;
	return 0;
}

int f(double in)
{
	return 1;
}
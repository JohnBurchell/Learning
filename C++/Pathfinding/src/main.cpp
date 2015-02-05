#include <iostream>

#include "graphics.h"
#include "graph.h"

class Graphics;


int main()
{
	Graphics graphics{};

	std::cout << "Hello from Nav" << std::endl;

	while(true)
	{
		graphics.clear();
		graphics.flip();

	}

	return 0;
}


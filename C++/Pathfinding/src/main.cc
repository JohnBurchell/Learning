#include <iostream>

#include "graphics.h"
#include "graph.h"

class Graphics;
class Graph;
class Edge;
class Node;
class NavNode;

void input();
void update();
void draw(Graphics& graphics);
void setup_graph(Graph& graph);

namespace
{
	constexpr float left_indent = 160;
	constexpr float top_indent = 160;

	constexpr int visited = 1;
	constexpr int blocked = 6;
	constexpr int current_best = 3;

}

Graph graph{};

int main()
{
	Graphics graphics{};

	setup_graph(graph);

	bool running = true;

	while(running)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) 
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				}
			}
		}

		input();
		update();
		draw(graphics);
	}

	return 0;
}

void setup_graph(Graph& graph)
{	
	graph.load("graph_data.txt");


	graph.goal = graph.get_node(4);
	graph.get_node(4).set_colour(4);

	graph.initial = graph.get_node(76);
	graph.get_node(76).set_colour(2);

	std::cout << "Graph created, " << graph.num_nodes() << " added." << std::endl;
}

void input()
{

}

void update()
{
	for(auto x : graph.m_nodes)
	{
		if(!x.active)
		{
			x.set_colour(visited);
		}
	}
}

void draw(Graphics& graphics)
{
	graphics.clear();

	for(auto x : graph.m_nodes)
	{
		auto pos = x.position();
		graphics.render_rectanlge(pos.y + left_indent, pos.x + top_indent, x.colour());
	}
	//Draw the "Nodes" as squares.
	//Draw the board here
	//Draw the "Traveller"

	graphics.flip();
}


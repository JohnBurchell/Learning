#include <iostream>

#include <limits>
#include <queue>

#include "graphics.h"
#include "graph.h"

class Graphics;
class Graph;
class Edge;
class Node;
class NavNode;

void input();
void update(Graph& graph);
void draw(Graphics& graphics);
void setup_graph(Graph& graph);

void bfs(Graph& graph, Node& node);
void dfs(Graph& graph, Node& node);
void dfs_visit(Graph& graph, Node& node, int& depth_time);
void a_star();
void dijkstra();

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
		update(graph);
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

	//bfs(graph, graph.initial);
	dfs(graph, graph.initial);
}

void input()
{

}

void print_graph(Graph& graph, Node& v, Node& s)
{
	while(s.previous != nullptr)
	{	
		graph.m_nodes[s.index()].set_colour(3);
		s = *s.previous;
	}
}

void update(Graph& graph)
{
	//Start with BFS.
	print_graph(graph, graph.initial, graph.goal);
}

void dfs(Graph& graph, Node& s)
{
	for(auto& x : graph.m_nodes)
	{
		if(x.index() != s.index())
		{
			x.set_colour(0);
			x.previous = nullptr;
		}
	}

	int depth_time = 0;

	for(auto& x : graph.m_nodes)
	{
		if(x.colour() == 0)
		{
			dfs_visit(graph, x, depth_time);
		}
	}
}

void dfs_visit(Graph& graph, Node& node, int& depth_time)
{	
	++depth_time;
	node.distance = depth_time;
	node.set_colour(9);

	//Explore edges
	for(auto& x : graph.m_edges[node.index()])
	{
		auto& to = graph.get_node(x.to());

		if(to.colour() == 0)
		{
			to.previous = &graph.get_node(node.index());
			dfs_visit(graph, to, depth_time);
		}

		if(to.index() == graph.goal.index())
		{
			std::cout << "Found you @ " << to.index() << std::endl;
			std::cout << graph.goal.previous->index() << std::endl;
		}
	}

	++depth_time;
}

void bfs(Graph& graph, Node& s)
{
	for(auto& x : graph.m_nodes)
	{
		if(x.index() != s.index())
		{
			x.set_colour(0);
			x.distance = std::numeric_limits<int>::max();
			x.previous = nullptr;
		}
	}

	//Creating some blocks
	graph.get_node(27).set_colour(blocked);
	graph.get_node(28).set_colour(blocked);
	graph.get_node(30).set_colour(blocked);
	graph.get_node(31).set_colour(blocked);
	graph.get_node(32).set_colour(blocked);
	graph.get_node(33).set_colour(blocked);
	graph.get_node(34).set_colour(blocked);
	graph.get_node(35).set_colour(blocked);

	graph.get_node(13).set_colour(blocked);
	graph.get_node(22).set_colour(blocked);

	graph.get_node(7).set_colour(blocked);
	graph.get_node(16).set_colour(blocked);

	graph.get_node(46).set_colour(blocked);
	graph.get_node(47).set_colour(blocked);
	graph.get_node(55).set_colour(blocked);
	graph.get_node(56).set_colour(blocked);

	s.set_colour(9);
	s.distance = 0;
	s.previous = nullptr;

	std::queue<Node> node_queue{};
	node_queue.push(s);

	while(!node_queue.empty())
	{
		Node& u = node_queue.front();
		node_queue.pop();

		for(auto& x : graph.m_edges[u.index()])
		{	
			auto& to = graph.get_node(x.to());

			if(to.colour() == 0)
			{
				to.set_colour(9);
				to.distance = (u.distance + 1);
				to.previous = &graph.get_node(u.index());

				node_queue.push(to);
			}

			if(to.index() == graph.goal.index())
			{
				graph.goal = graph.get_node(to.index());
				to.set_colour(3);
				return;
			}
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


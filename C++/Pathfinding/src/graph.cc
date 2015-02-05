#include "graphics.h"
#include "graph.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::string;

Graph::Graph() :
	m_edges{},
	m_nodes{},
	m_directed{false},
	m_next_node_index{}
{

}

Graph::Graph(bool directed) :
	m_edges{},
	m_nodes{},
	m_directed{},
	m_next_node_index{0}
{

}

Node& Graph::get_node(int i) 
{
	return m_nodes[i];
}

Edge& Graph::get_edge(int from, int to)
{
	auto iterator = m_edges[from].begin();
	std::advance(iterator, to);
	return *iterator;
}

int Graph::add_node(Node& node)
{
	m_nodes.emplace_back(node);
	m_edges.emplace_back(Edge_List{});
}

void Graph::remove_node(int index)
{

}

void Graph::add_edge(Edge& edge)
{
	m_edges[edge.from()].emplace_back(edge);
}

void Graph::remove_edge(int to, int from)
{

}

int Graph::num_nodes() const
{
	return m_nodes.size();
}

int Graph::num_active_nodes() const
{

}

int Graph::num_edges() const
{

}

void Graph::load(std::string& filename)
{

	std::fstream input{filename};
	std::string line;

	std::vector<string> adjacency{};

	while(getline(input, line) && line != "ENDOFLINE")
	{
		size_t hyphen = line.find("-");

		string number = line.substr(0, hyphen);
		string edges = line.substr(hyphen+1, line.size());

		//Potentially remove this later
		adjacency.emplace_back(edges);

		Node node{stoi(number)};
		add_node(node);

	}


	for(int i = 0; i < adjacency.size(); ++i)
	{
		std::stringstream ss;

		string current = adjacency[i];
		size_t next = 0;
		while(next != current.size())
		{
			next = current.find(',');
		}

		std::cout << "--" << std::endl;
	}

	int count = 0;
	for(int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			m_nodes[count].m_position.x = (float) i * 34;
			m_nodes[count].m_position.y = (float) j * 34;
			++count;
		}
	}
}

void Graph::load(const char* filename)
{
	std::string file{filename};
	load(file);
}

void Graph::save(std::string& filename) const
{
	std::fstream input{filename};
}


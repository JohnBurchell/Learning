#ifndef GRAPH_H_
#define GRAPH_H_

#include "node.h"
#include "edge.h"

#include <vector>
#include <list>

class Graph
{
public:

	using Edge_List = std::list<Edge>;
	using Edge_List_Vector = std::vector<Edge_List>;
	using Node_Vector = std::vector<Node>;

	class Edge_Iterator;

	Graph();
	Graph(bool directed);

	Node& get_node(int i);
	Edge& get_edge(int from, int to);

	int add_node(Node& node);
	void remove_node(int index);

	void add_edge(Edge& edge);
	void remove_edge(int to, int from);

	int num_nodes() const;
	int num_active_nodes() const;
	int num_edges() const;

	void load(std::string& filename);
	void load(const char* filename);

	void save(std::string& filename) const;
	void save(const char* filename) const;

	Node_Vector m_nodes;

	Node goal;
	Node initial;
	Node current_best;

private:
	Edge_List_Vector m_edges;
	bool m_directed;
	int m_next_node_index;

};

#endif //GRAPH_H_
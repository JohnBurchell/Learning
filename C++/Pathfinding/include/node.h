#ifndef NODE_H_
#define NODE_H_

#include "vector2d.h"

class Node
{

	public:
		Node() : m_index{-1}, m_colour{0}, active{true} {};
		Node(int i, float x, float y) : m_index{i}, m_colour{0}, m_position{x,y}, active{true}, previous{nullptr}, distance{0} {};
		Node(int id) : m_index{id}, m_colour{0}, active{true} {};

		inline int index() const { return m_index; };
		inline void set_index(const int index) { m_index = index; };

		inline int colour() const { return m_colour; };
		inline void set_colour(int colour) { m_colour = colour; };


		inline vector2d position() const { return m_position; };
		inline void set_vector(vector2d newPosition) { m_position = newPosition; };

		//m_index should correspond to where the edges lie for this node, fast lookup of O(1) if so!
		vector2d m_position;
		int m_index;
		int m_colour;
		bool active;
		Node* previous;
		int distance;

};

#endif //NODE_H_
#ifndef NODE_H_
#define NODE_H_

#include "vector2d.h"

class Node
{
	protected:
		int m_index;
	public:
		Node() : m_index{-1} {};
		Node(int id) : m_index{id} {};

		virtual ~Node();

		inline int index() const { return m_index; };
		inline void set_index(const int index) { m_index = index; };
};

class NavNode : public Node
{
	private:
		vector2d m_position;
		//Extra info, not sure what this could be yet - Template is used in the example.

	public:
		inline vector2d position() const { return m_position; };
		inline void set_vector(vector2d newPosition) { m_position = newPosition; };
};

#endif //NODE_H_
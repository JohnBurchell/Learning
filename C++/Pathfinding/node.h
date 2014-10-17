#ifndef NODE_H_
#define NODE_H_

#include "vector2d.h"

class Node
{
	protected:
		int index_;
	public:
		Node() : 
		index_{-1} {};
		Node(int id) : index_{id}{};

		virtual ~Node();

		inline int index() const { return index_; };
		inline void setIndex(const int index) { index_ = index; };
};

class NavNode : public Node
{
	private:
		vector2d position_;
		//Extra info, not sure what this could be yet - Template is used in the example.

	public:
		inline vector2d position() const { return position_; };
		inline void setVector(vector2d newPosition) { position_ = newPosition; };
};

#endif //NODE_H_
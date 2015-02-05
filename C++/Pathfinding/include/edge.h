#ifndef EDGE_H_
#define EDGE_H_

class Edge
{
	protected:
		int m_from;
		int m_to;
		double m_weight;
	public:
		Edge(int from, int to, double weight) :
			m_from{from},
			m_to{to},
			m_weight{weight} {};

		Edge(int from, int to) :
			m_from{from},
			m_to{to},
			//Arbitrary weight when none is given
			m_weight{10} {};

		inline int from() const { return m_from; };
		inline void set_from(int from) { m_from = from; };

		inline int to() const {return m_to; };
		inline void set_to(int to) { m_to = to; };

		inline int weight() const { return m_weight; };
		inline void set_weight(int weight) { m_weight = weight; };
};

#endif //EDGE_H_
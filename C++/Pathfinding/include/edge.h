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
		inline void setFrom(int from) { m_from = from; };

		inline int to() const {return m_to; };
		inline void setTo(int to) { m_to = to; };

		inline int weight() const { return m_weight; };
		inline void setWeight(int weight) { m_weight = weight; };
};

#endif //EDGE_H_
#ifndef EDGE_H_
#define EDGE_H_

class Edge
{
	protected:
		int from_;
		int to_;
		double weight_;
	public:
		Edge(int from, int to, double weight) :
			from_{from},
			to_{to},
			weight_{weight} {};

		Edge(int from, int to) :
			from_{from},
			to_{to},
			//Arbitrary weight when none is given
			weight_{10} {};

		inline int from() const { return from_; };
		inline void setFrom(int newFrom) { from_ = newFrom; };

		inline int to() const {return to_; };
		inline void setTo(int newTo) { to_ = newTo; };

		inline int weight() const { return weight_; };
		inline void setWeight(int newWeight) { weight_ = newWeight; };
};

#endif //EDGE_H_
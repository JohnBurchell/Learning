#include "Histogram.h"

using namespace std;

Histogram::Histogram(const vector<int>& rr, const int ii) :

	range(rr),
	interval(ii)

	{
		if (rr.size() < 1) {
			throw bad_histogram();
		}
		else if (ii > rr.size()){
			//Changing to a default interval is another method
			throw bad_interval();
		}
		init_histogram();
};

const void Histogram::init_histogram()
{
	for (size_t i = 0; i < range.size(); ++i){
		histogram.push_back("");
	}
	generate_histogram();
}

const void Histogram::generate_histogram()
{
	for (auto& x : range){
		if (x % interval == 0){
			histogram.at(x) += 'X';
		}
	}
}

const void Histogram::print_histogram()
{
	for (auto& x : histogram){
		static int count = 0;
		if (x.size() > 0){
			cout << count << " " << x << endl;
		}
		++count;
	}
}

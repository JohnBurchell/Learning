#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
(∗2) Define a class Histogram that keeps count of numbers in some intervals specified as
arguments to Histogram’s constructor. Provide functions to print out the histogram. Handle
out-of-range values.
*/

class Histogram {

public:

	class bad_histogram {};
	class bad_interval {};

	explicit Histogram(const std::vector<int>& rr, const int ii = {});

	const void print_histogram();

private:

	const void generate_histogram();
	const void init_histogram();

	std::vector<int> range;
	std::vector<std::string> histogram;
	int interval;
};


#endif
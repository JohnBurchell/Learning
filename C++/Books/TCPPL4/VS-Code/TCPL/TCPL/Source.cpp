#include <iostream>
#include "Date.h"
#include "Histogram.h"

using namespace std;

/*
--------------------------------------------------------------------
Ex1 - Finding & fixing errors:
--------------------------------------------------------------------
*/


int main()
{
	Date today{};
	cout << today.day() << endl;
	cout << static_cast<int>(today.month()) << endl;
	cout << today.year() << endl;
	cout << today.string_rep() << endl;

	vector<int> ints = { 1,1,1,1,1,2,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,9,9,9 };
	vector<int> test = { 1 };
	Histogram histo{ints, 2};
	histo.print_histogram();
	system("pause");
}
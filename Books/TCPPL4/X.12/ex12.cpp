#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

int res = 0;

using namespace std;
using namespace chrono;

//Ex 1 (2)
void memory_overflow(bool write)
{
	int size = 1000, count = 0;
	std::vector<char> v;

	try {

		while (true) {

			char *arr = new char[size];
			v.push_back(*arr);

			if (write) {
				for (int i = 0; i < size; i++) {
					arr[i] = 'x';
				}
			}

			++count;
		}
	}
	catch (std::bad_alloc) {

		std::cerr << "Memory max reached, used " << count * size << " bytes." << std::endl;
	}
}


/*
---------------------------------------------------------------------------------------------
Ex 3 - lots of stuff here
---------------------------------------------------------------------------------------------
*/
int sum(int a, int b,)
{
	return b += a;
}
int accu_for(vector<int>* vec, int accu)
{
	vector<int>::const_iterator iter = vec->begin();
	for (; iter != vec->end(); ++iter){
		accu += *iter;
	}
	return accu;
}
int accu_range_for(vector<int>* vec, int accu)
{
	for (auto& x : *vec){
		accu += x;
	}
	return accu;
}
int accu_pointer(vector<int>* vec, int accu)
{
	int count = 0, size = vec->size();
	while (count < size){
		accu += vec->at(count);
		++count;
	}
	return accu;
}
int accu_indices(vector<int>* vec, int accu)
{
	int count = 0, size = vec->size();
	while (count < size){
		accu += vec->operator[](count);
		++count;
	}
	return accu;
}
int accu_for_each(vector<int>* vec, int accu)
{
	std::for_each(vec->begin(), vec->end(), sum(int, accu));
	return accu + res;
}
//Function object, or functor
class Sum_object {

	int& accu;
	
public:
	Sum_object(int& m_accu) : accu(m_accu) {}
	void operator()(int y) { accu += y; }
};

int accu_fun_obj(vector<int>* vec, int accu)
{
	for_each(vec->begin(), vec->end(), Sum_object{ accu });
	return accu;
}
int accu_lambda(vector<int>* vec, int accu)
{
	auto lambda_sum = [&accu](int x) { return accu += x; };
	for_each(vec->begin(), vec->end(), lambda_sum);
	return accu;
}

/*
---------------------------------------------------------------------------------------------
Ex 4 
---------------------------------------------------------------------------------------------
*/
struct Shape {
	string name;
	int value;
};

template <class T>
void apply(vector<Shape*> shapes, T (*f)(T))
{
	for (auto& x : shapes) {
		(*f)(x->value);
	}
}

int print_received(int rec)
{
	cout << rec << endl;
	return 0;
}

int mult(int num)
{
	cout << num * 5 << endl;
	return num * 5;
}

class FunObj {

};

int random_num()
{
	return rand() % 1000 + 1;
}

int main()
{
	//Ex3
	std::random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> uniform(1, 10000);
	int random = uniform(eng);

	vector<int> values;

	std::cout << "Randomly-chosen int: " << random << '\n';

	while (random > 0) {
		values.push_back(random);
		--random;
	}

	std::cout << values.size() << endl;

	vector<Shape*> shapes;
	Shape* one = new Shape { "john", 50 };
	Shape* two = new Shape { "Mikis", 60 };
	Shape* three = new Shape { "Chris", 70};

	shapes.push_back(one);
	shapes.push_back(two);
	shapes.push_back(three);

	apply(shapes, print_received);
	apply(shapes, mult);
	apply(shapes, sum);

	vector<int>* v_p = &values;

	//Noticed small time increases for functor and pointers, otherwise VERY similar, I might add more later.
	cout << "For each - plain : " << accu_for_each(v_p, 0) << endl;
	cout << "Pointers - plain : " << accu_pointer(v_p, 0) << endl;
	cout << "function Object  : " << accu_fun_obj(v_p, 0) << endl;
	cout << "lambda for each  : " << accu_lambda(v_p, 0) << endl;

	system("pause");
}


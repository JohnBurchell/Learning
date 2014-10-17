#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include "Lexer.h"

using namespace std;

typedef map <string, float>::const_iterator c_it;
typedef vector <float>::const_iterator cv_it;

float median(vector<float> series);

//Global for now... :(



/* Ex1

a = ((b + (c ∗ d)) << 2) & 8
(a & 077) != 3
(a == b) || (a == c) && (c < 5)
c = (x != 0)
0 <= (i < 7)
(f(1,2)) + 3
a = - (1 + (+ b--)) - 5; -- Don't know this one
a = (b == (c ++))
a = (b = (c = 0))
a[4][2] ∗= (∗ b) ? c : ∗ (d ∗ 2)
(a−b),(c=d)

*/

/* Ex6

∗(p++)
∗(−−p)
(++a)−−
(int∗)p−>m
(∗p.m)
(∗a)[i]

*/


//Ex2
map < string, float >* ex2()
{
	std::string str, name;
	float value;

	map < string, float >* my_map = new map < string, float >;

	while (std::cin) {
		getline(cin, str);
		stringstream(str) >> name;
		getline(cin, str);
		stringstream(str) >> value;

		my_map->emplace(name, value);
	}

	return my_map;
}

//Ex2 helper
void printer(const map <string, float>* map)
{
	c_it iter = map->begin();

	float result = 0;
	int count = 0;

	vector<float> series;

	while (iter != map->end()){
		result += iter->second;
		++count;
		cout << "Name : " << iter->first << endl;
		cout << "Sum : " << result << " Mean : " << result / count << endl;
		series.push_back(iter->second);
		++iter;
	}

	cout << "Total Sum : " << result << " Total Mean : " << result / count << " Median : " << median(series) << endl;
}

//Ex8
float median(vector<float> series)
{
	//if odd, return the middle number
	if (int size = series.size() % 2 == 1){
		return series.at(size / 2);
	}
	else {
		size = series.size() / 2;
		return static_cast<float>((series.at(size) + series.at(size - 1)) / 2.0);
	}
}

//Ex3 - Bitwise operators
void bitwise()
{
	//This could be improved so much with a proper tokenizer etc but it seems a little un-needed for a *1 problem.
	map < string, int > operators;

	operators.emplace("&&", 0);
	operators.emplace("||", 0);
	operators.emplace("!", 0);

	for (auto& x : operators) {
		if (x.first == "&&") {

			cout << (!x.second && x.second) << " - ";
			cout << (x.second && !x.second) << " - ";
			cout << (x.second && x.second) << " - ";
			cout << (!x.second && !x.second) << endl;

		}
		else if (x.first == "||") {
			cout << (!x.second || x.second) << " - ";
			cout << (x.second || !x.second) << " - ";
			cout << (x.second || x.second) << " - ";
			cout << (!x.second || !x.second) << endl;
		}
		else if (x.first == "!") {
			cout << x.second << " - ";
			cout << !x.second << endl;
		}

		else {
			cout << "Incorrect operator given." << endl;
		}
	}
}
//Ex7
int my_strlen(char* str)
{
	int count = 0;
	char* c = str;
	while (*c != '\0'){
		++c;
		++count;
	}
	return count;
}
//Ex7
int my_strcpy(char* dest, const char* src)
{
	char* p_dest = dest;
	const char* p_src = src;
	try{
		while (*p_src != '\0'){
			*p_dest = *p_src;
			++p_dest, ++p_src;
		}
		//don't forget to add to stop cout
		*p_dest = '\0';
	}

	catch (bad_alloc){
		cout << "Memory exhausted" << endl;
		return 1;
	}

	return 0;
}
//Ex7
int my_strcmp(char* const a, char* const b)
{
	const char* p_a = a;
	const char* p_b = b;
	while ((*p_a++) == (*p_b++)){

	}

	return *p_a == '\0' ? 0 : 1;
}
//Ex9
char* my_cat(char* a, char* b)
{
	char* concat = new char[];
	char* p_a = a;
	char* p_b = b;
	char* p_concat = concat;

	while (*p_a != '\0'){
		*p_concat = *p_a;
		++p_a, ++p_concat;
	}
	while (*p_b != '\0'){
		*p_concat = *p_b;
		++p_b, ++p_concat;
	}
	
	*p_concat = '\0';
	return concat;
}
//Ex10
char* my_rev(char* rev)
{
	char* p_rev = rev;
	char* temp = new char[];
	int count = 0;

	while (*p_rev != '\0'){
		++count, ++p_rev;
	}

	p_rev = rev;
	temp[count] = '\0';
	--count;

	while (count >= 0) {
		temp[count] = *p_rev;
		--count, ++p_rev;
	}

	return temp;
}



int mains()
{
	//map <string, float>* map = ex2();
	//printer(map);
	//Ex 5 - Build error when attempting to div by zero, a crash when it's abstracted and the compiler can't see it
	int count = my_strlen("hello\0");
	char* test = "hello";
	char* other = new char[];

	my_strcpy(other, test);
	cout << other << endl;
	cout << count << endl;
	cout << my_strcmp(other, test) << endl;

	char* cat_test = my_cat(test, other);

	cout << cat_test << endl;

	char* another = "mikaela";
	another = my_rev(another);
	cout << another << endl;
	
	//Ex11-14 included seperatly
	system("pause");

	return 0;
}


#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <regex>
#include <math.h>

void reWritten()
{

	int quest_count = 0, i = 0, max_length = 5;
	std::array<int, 5> input_line;

	while (i != max_length)
	{
		if (input_line[i] == '?')
		quest_count++;
		++i;
	}
}

void send(int* to, int* from, int count)
{
	int n = (count + 7) / 8;

	switch (count % 8) {
	case 0: 
	do { 
		    *to++ = *from++;
	case 7: *to++ = *from++;
	case 6: *to++ = *from++;
	case 5: *to++ = *from++;
	case 4: *to++ = *from++;
	case 3: *to++ = *from++;
	case 2: *to++ = *from++;
	case 1: *to++ = *from++;

	} while (--n > 0);
	}
}

//Ex2 excluded as it won't compile (obviously!)

/* Ex3
	Fallthrough I would imagine but a computation would occur./
	VS was crashing with buffer overflow too.
*/

//Ex4 - Not sure if the intention was to avoid using library functions or not
//But i have used some anyway.
int my_atoi(const char* in)
{
	int result = 0;
	enum type {decimal, octo, hex};
	type T = type::decimal;

	if(*in == '0') { 
		T = type::octo;
		++in;
	}
	if(*in == 'x') {
		T = type::hex;
		++in;
	}

	switch (T) {

	case type::octo:
		return std::stoul(in, nullptr, 8);
	case type::hex:
		return std::stoul(in, nullptr, 16);
	case type::decimal:
		while(*in != '\0') {
			result = (result * 10) + (*in - 48);
			++in;
		}
		break;
	}
	return result;
}

//Ex 5 & 6
char* my_itoa(int i, char b[], int len)
{
	if(len == 0){
		return b;
	}

	//Get individual digit
	int digit = i % 10 + 48;
	//Place them in reverse
	b[len-1] = static_cast<char>(digit);
	//Recurse
	return my_itoa(i/10, b, len-1);
}

void stripper(std::string fileName)
{
	std::ifstream input;
	std::string str;
	input.open(fileName);

	//Basic comments in the form of //
	std::regex pat1 ("(//\s*)(.*)");
	//A starting /*
	std::regex pat2 ("\/[*]");
	//An ending \*
	std::regex pat3 ("\*/", std::regex_constants::basic);
	//Looks for comments in the style of /* */ on the same line.
	std::regex pat4 ("(/[*])(.*)([*]/)");

	std::smatch matches;
	int lineno = 0;

	std::cout << "Line nr | Comment" << std::endl;

	while(getline(input, str)) {

		if(std::regex_search(str, matches, pat1)){
			std::cout << lineno << " : " << matches[2] << std::endl;
		}
		else if(std::regex_search(str, matches, pat4)){
			std::cout << lineno << " : " << matches[2] << std::endl;
		}
		else if(std::regex_search(str, matches, pat2)){
			//Debug for comment start points
			//std::cout << lineno << " : " << matches[0] << std::endl; 
			//found new full comment
			while(getline(input, str)) {
				if(std::regex_search(str, matches, pat3)){
					//Debug for comment end points
					//std::cout << lineno << " : " << matches[0] << std::endl;
					break;
				} else {
					std::cout << lineno << " : " << str << std::endl;
					++lineno;
				}
			}
		}
		++lineno;
	}

	//Always close
	input.close();
}



int main() 
{
	stripper("Source.cpp");
	system("pause");
}


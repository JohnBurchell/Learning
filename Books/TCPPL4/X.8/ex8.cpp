#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

int globalInts[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

void ex1() 
{

	//Pointer to a char
	char theChar = 'z';
	char* pchar = &theChar;
	//Array of 10 ints
	int ten[10] = { 91, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//Pointer to array of 10 ints
	int* pten = ten;
	//Reference to array of 10 ints.
	int (&ref)[sizeof(ten)/sizeof(int)] = ten;
	//Above is more "dynamic" but harder to read, do this instead?
	int (&ref2)[10] = ten;
	//DONT forget that string literals in this useage are constants. Declare them as so.
	const char* array_strings[4] = { "Hello", "World", "It's", "Me!"};
	//Point to the ref of the pointer to the char. 
	char** ppchar = &pchar;
	//constant int.
	const int c_int = 10;
	//pointer to const int
	const int* const_int = &c_int;
	//const pointer to a const int
	int const* pc_int = &c_int;
}

void ex2()
{

	int odd = 21, even = 22, odd2 = 29;
	int* pOdd1 = &odd;
	int* pEven = &even;
	int* pOdd2 = &odd2;

	char evenC = 'a';
	char oddC = 'b';
	char evenC2 = 'c';	

	char* pEvenC = &evenC;
	char* pOddC = &oddC;
	char* pEvenC2 = &evenC2;

	void *pVoid;

	std::cout << " Ints " << std::endl;
	printf("%p\n", pOdd1);
	printf("%p\n", pEven);
	printf("%p\n", pOdd2);

	std::cout << " Chars " << std::endl;
	printf("%p\n", pEvenC);
	printf("%p\n", pOddC);
	printf("%p\n", pEvenC2);

	std::cout << " Void " << std::endl;
	printf("%p\n", pVoid);

}

void ex3()
{
	using uc = unsigned char;
	using ConstUc = const unsigned char;
	//Pointer to int
	using p2int = int*;
	//Pointer to pointer to char
	using pp2char = char**;
	//Pointer to array of 10 chars
	using p2charArr = const char* [10];
	//Array of 7 pointers to ints
	using pointersToInts = int* [7];

	//Little unsure of these two!
	//Pointer to array of 7 int pointers
	using p_pointersToInts = int** [7];
	//Array of 8 arrays of 7 int pointers
	using array_to_array_ints = int** [8][7];

}

template<class T>
int findDiff(T* type, const int &range)
{
	T* p_start = type;
	T* p_end = type + range;

	int count = 0;

	while(*p_start != *p_end) {
		++count;
		++p_start;
	} 

	return count;
}

void ex6()
{	
	//This stuff will obviously crash.

	class Member{

	public:
		int memberInts[20];
	};

	Member member;
	int localInts[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	int* newInts = new int[20];

	std::cout << " Reading global ints " << std::endl;
	std::cout << globalInts[-1];
	std::cout << globalInts[-200000000000];
	std::cout << globalInts[-200000000000];
	std::cout << globalInts[-200000000000];

	std::cout << " Reading member ints " << std::endl;
	std::cout << member.memberInts[-1];
	std::cout << member.memberInts[-200000000000];
	std::cout << member.memberInts[-200000000000];
	std::cout << member.memberInts[-200000000000];

	std::cout << " Reading local  ints " << std::endl;
	std::cout << localInts[-1];
	std::cout << localInts[-200000000000];
	std::cout << localInts[-200000000000];
	std::cout << localInts[-200000000000];

	std::cout << " Reading newInt ints " << std::endl;
	std::cout << newInts[-1];
	std::cout << newInts[-200000000000];
	std::cout << newInts[-200000000000];
	std::cout << newInts[-200000000000];

	delete newInts;

}

void swapWithPointers(int* a, int* b) 
{

	int temp{*a};
	*a = *b;
	*b = temp;
}

void swapWithReferences(int& a, int& b) 
{

	int temp{a};
	a = b;
	b = temp;
}

void ex8()
{
	char str[] = "a short string";
	//14 was an educated guess, but 15 is correct because of the termintor.
	std::cout << sizeof(str) << std::endl;

	std::string str2 = "a short string";
	//This was 4, better storage perhaps?
	std::cout << sizeof(str2) << std::endl;
}

void f(char c)
{
	std::cout << c << std::endl;
}

void g(char& c) 
{
	std::cout << c << std::endl;
}

void h(const char& c)
{
	std::cout << c << std::endl;
}

void ex10(const char* months[])
{
	while(*months != '\0'){
		std::cout << *months << std::endl;
		*months++;
	}
}

void ex11()
{	

	std::vector<std::string> input;
	std::vector<std::string>::const_iterator str_iter;
	std::cout << "Enter some words, type Quit to stop." << std::endl;


	while(std::cin) {
		std::string word;
		std::cin >> word;

		if(word == "Quit") {
			
			std::cout << "\n\nYou entered pre sort: \n\n" << std::endl;
			for(str_iter = input.begin(); str_iter != input.end(); str_iter++){

				std::cout << *str_iter << std::endl;
			}

			//Sort
			std::sort(input.begin(), input.end());

			std::cout << "\n\nYou entered post sort: \n\n" << std::endl;
			for(str_iter = input.begin(); str_iter != input.end(); str_iter++){

				std::cout << *str_iter << std::endl;
			}

			return;
		}

		if((str_iter = std::find(input.begin(), input.end(), word)) == input.end()) {
			//If the iter returns the end of the vector, the word doesn't already exist.
			input.push_back(word);
		}

		//Implicit else, don't add if it's alread there.
	}
}

void ex12_a(std::string &str, std::string &pattern)
{
	std::string::const_iterator str_iter = str.begin();
	std::string::const_iterator pattern_iter = pattern.begin();

	int count = 0;

	while(str_iter != str.end()){
		//If the same, increase counter and move iter
		if(*str_iter == *pattern_iter){
			++pattern_iter;

			if(pattern_iter == pattern.end()) {
				++count;
			}

		} else {
			//Else the don't match, move the pattern iter back
			pattern_iter = pattern.begin();
		}

		++str_iter;
	}

	std::cout << "\n\nPattern " << pattern << " appears " << count << " times." << std::endl;	
}

void ex12_b(char* cStyle, char* pattern)
{
	const char* p_str = cStyle;
	const char* p_pattern;

	int count = 0;

	while(*p_str != '\0') {

		if(*p_str == *p_pattern) {
			++p_pattern;

			if(*p_pattern == '\0') {
				++count;
			}
		} else {
			//reset
			p_pattern = pattern;
		}
		++p_str;
	}

	std::cout << "\n\nPattern " << pattern << " appears " << count << " times." << std::endl;	

}


int main() 
{
	ex1();
	ex2();
	ex3();

	//Ex 4
	char longWord[] = {"abcdefghij"};
	int result = findDiff(longWord, 5);
	std::cout << "\nFor chars the diff is " << result << std::endl;

	//Ex 5
	int ints[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	result = findDiff(ints, 7);
	std::cout << "\nFor ints the diff is " << result << std::endl;

	//Crashes, unsurprisingly.
	//ex6();

	//Ex7
	int a = 10, b = 20;
	std::cout << "before sawp " << a << " " << b << std::endl;
	int* pa = &a;
	int* pb = &b;
	swapWithPointers(pa, pb);
	std::cout << "after sawp " << a << " " << b << std::endl;

	std::cout << "before sawp " << a << " " << b << std::endl;
	int &aRef = a;
	int &bRef = b;
	swapWithReferences(a, b);
	std::cout << "after sawp " << a << " " << b << std::endl;

	ex8();

	//Ex9
	char char_one = 'a'; //Works in all, wont create temp
	int first = 49; // works in all but g, wont create temp
	int second = 3300; // works in all but g, might create a temp, 3300 is bigger than a byte.
	char c = 'c'; //works in all, won't create a temp
	unsigned char uc = 'u'; //works in all but g, will create a temp as there's no direct conversion to a char from unsigned
	signed char sc = 's'; //works in all but g, again, will create a temp as there's no direct converions between a normal char and signed

	const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	//Easier way is to pass the length of the array in with the array itself, as an array is stupid and cannot hold it's own size.
	ex10(months);
	ex11();

	//a
	std::string input = "xabaacbaxabb";
	std::string pattern = "ab";
	ex12_a(input, pattern);
	//b
	char input2[] = {"xabaacbaxabb"};
	char pattern2[] = {"ab"};
	ex12_b(input2, pattern2);

	int test;
	std::cout << "\n\n\n\n\nPress any key to quit";
}

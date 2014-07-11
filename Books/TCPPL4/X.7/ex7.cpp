#include <iostream>
#include <string>

void exerc_6() 
{

	enum nums {one, two, three, four};
	enum colours {red, green, blue, orange, blac, yellow, purple, pink, maroon, grey, chocolate, elephant, blueish, redish};

	
	std::cout << " Types ------------ | Sizes ----- " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << " normal int             " << sizeof(int) << std::endl;
	std::cout << " signed int             " << sizeof(signed int) << std::endl;
	std::cout << " unsigned int           " << sizeof(unsigned int) << std::endl;
	std::cout << " long int               " << sizeof(long int) << std::endl;
	std::cout << " long long int          " << sizeof(long long int) << std::endl;
	std::cout << " long unsigned int      " << sizeof(long unsigned int) << std::endl;
	std::cout << " long signed int        " << sizeof(long signed int) << std::endl;
	std::cout << " short  int             " << sizeof(short unsigned int) << std::endl;
	std::cout << " short signed int       " << sizeof(short signed int) << std::endl;
	std::cout << " short unsigned int     " << sizeof(short unsigned int) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << " normal double          " << sizeof(double) << std::endl;
	std::cout << " long float             " << sizeof(long float) << std::endl;
	std::cout << " long double            " << sizeof(long double) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << " normal char            " << sizeof(char) << std::endl;
	std::cout << " unsigned char          " << sizeof(unsigned char) << std::endl;
	std::cout << " signed char            " << sizeof(signed char) << std::endl;
	std::cout << " wide char              " << sizeof(__wchar_t) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << " char pointer           " << sizeof(char*) << std::endl;
	std::cout << " int pointer            " << sizeof(int*) << std::endl;
	std::cout << " double pointer         " << sizeof(double*) << std::endl;
	std::cout << " float pointer          " << sizeof(float*) << std::endl;
	std::cout << " bool pointer           " << sizeof(bool*) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << " enum #1                " << sizeof(nums) << std::endl;
	std::cout << " enum #2                " << sizeof(colours) << std::endl;
	std::cout << "----------------------------------" << std::endl;

}

void exerc_7()
{
	char start = 'a';
	std::cout << " Char - integer - hex" << std::endl;
	for(int i = 0; i < 24; i++) {
		std::cout << start << " : " << (int)start << " : "  << std::hex << int(start) <<std::endl;
		start++;
	}

	std::cout << std::dec << " ----------------------- " << std::endl;
}

void exerc_8()
{
	std::cout << " Limits of numbers " << std::endl;

	std::cout << " Max limit of an bool			 " << std::numeric_limits<bool>::max() << std::endl;
	std::cout << " Min limit of an bool			 " << std::numeric_limits<bool>::min() << std::endl;
	std::cout << " Max limit of an char			 " << std::numeric_limits<char>::max() << std::endl;
	std::cout << " Min limit of an char			 " << std::numeric_limits<char>::min() << std::endl;
	std::cout << " Max limit of an short		 " << std::numeric_limits<short>::max() << std::endl;
	std::cout << " Min limit of an short		 " << std::numeric_limits<short>::min() << std::endl;
	std::cout << " Max limit of an int			 " << std::numeric_limits<int>::max() << std::endl;
	std::cout << " Min limit of an int			 " << std::numeric_limits<int>::min() << std::endl;
	std::cout << " Max limit of an long			 " << std::numeric_limits<long>::max() << std::endl;
	std::cout << " Min limit of an long		     " << std::numeric_limits<long>::min() << std::endl;
	std::cout << " Max limit of an long long     " << std::numeric_limits<long long>::max() << std::endl;
	std::cout << " Min limit of an long long     " << std::numeric_limits<long long>::min() << std::endl;
	std::cout << " Max limit of an float         " << std::numeric_limits<float>::max() << std::endl;
	std::cout << " Min limit of an float         " << std::numeric_limits<float>::max() << std::endl;
	std::cout << " Max limit of an double        " << std::numeric_limits<double>::max() << std::endl;
	std::cout << " Min limit of an double        " << std::numeric_limits<double>::min() << std::endl;
	std::cout << " Max limit of an long double   " << std::numeric_limits<long double>::max() << std::endl;
	std::cout << " Min limit of an long double   " << std::numeric_limits<long double>::min() << std::endl;
	std::cout << " Max limit of an unsigned long " << std::numeric_limits<unsigned long>::max() << std::endl;
	std::cout << " Min limit of an unsigned long " << std::numeric_limits<unsigned long>::min() << std::endl;
	std::cout << " Max limit of an signed long   " << std::numeric_limits<signed long>::max() << std::endl;
	std::cout << " Min limit of an signed long   " << std::numeric_limits<signed long>::min() << std::endl;

}

void exerc_9()
{
	std::cout << " a bool is          " << sizeof(bool) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a char is          " << sizeof(char) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a char is          " << sizeof(short) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a int  is          " << sizeof(int) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a long is          " << sizeof(long) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a long long is     " << sizeof(long long) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a float is         " << sizeof(float) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a double is        " << sizeof(double) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a long double is   " << sizeof(long double) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a unsigned long is " << sizeof(unsigned long) / sizeof(char) << " character(s) long " << std::endl;
	std::cout << " a signed long is   " << sizeof(signed long) / sizeof(char) << " character(s) long " << std::endl;
}

int main() 
{

	char c = 255;

	int i = c;

	c == 255 ? std::cout <<  "Chars are unsigned" << std::endl : std::cout << "Chars are signed" << std::endl;

	exerc_6();
	exerc_7();
	exerc_8();
	exerc_9();


	system("pause");
}


#include <iostream>


void write4();
void read4();


int main() {
	
	write4();
	read4();
}

void write4() {

	bool   boolean = false;
	char   c = 'A';
	int    i = 0;
	double d = 10.0;
	std::string s = "Hello i am a string";

	std::cout << "This is a bool " << boolean << std::endl;
	std::cout << "This is a char " << c << std::endl;
	std::cout << "This is a int " << i << std::endl;
	std::cout << "This is a double " << d << std::endl;
	std::cout << "This is a string " << s << std::endl;

}

void read4() {

	bool   boolean;
	char   c;
	int    i;
	double d;
	std::string s;

	std::cout << "Give me a bool: " << std::endl;
	std::cin >> boolean;
	std::cout << "Give me a char: " << std::endl;
	std::cin >> c;
	std::cout << "Give me a int: " << std::endl;
	std::cin >> i;
	std::cout << "Give me a double: " << std::endl;
	std::cin >> d;
	std::cout << "Give me a string: " << std::endl;
	std::cin >> s;

	std::cout << "bool " << boolean << std::endl;
	std::cout << "char " << c << std::endl;
	std::cout << "int " << i << std::endl;
	std::cout << "double " << d << std::endl;
	std::cout << "string " << s << std::endl;

}
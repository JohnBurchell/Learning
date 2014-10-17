#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

enum class Kind : char {
	name, number, end,
	plus = '+', minus = '-', mul = '*', div = '/', print = ';', assign = '=', lp = '(', rp = ')', fun = 'F', newln = '\n'
};

struct Token {
	Kind kind;
	std::string string_value;
	double number_value;
};

struct Function {
	std::vector<Token> tokens;
};

class Token_stream {
public:
	Token_stream(std::istream& s) : ip{ &s }, owns(false) {}
	Token_stream(std::istream* p) : ip{ p }, owns(true) {}

	~Token_stream() { close(); }

	Token get();
	//Bjarne didn't include this, but I presume it's correct
	Token& current() { return ct; };

	void set_input(std::istream& s) { close(); ip = &s; owns = false; }
	void set_input(std::istream* p) { close(); ip = p; owns = true; }

private:
	void close() { if (owns) delete ip; }

	std::istream* ip;
	bool owns;
	bool record;
	Token ct;
	std::map<std::string, Function> functions;


};

double prim(bool get);
double term(bool get);
double expr(bool get);

#endif
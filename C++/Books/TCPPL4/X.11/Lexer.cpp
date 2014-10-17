#include "Lexer.h"
#include <map>

using namespace std;

int no_of_errors;
int line_no;

Token_stream ts{ cin };
map<string, double> table;

int error(const string& s, const int& line)
{
	no_of_errors++;
	cerr << "error: " << s << " line: " << line << "\n";
	line_no++;
	return 1;
}

Token Token_stream::get()
{

	char ch;

	do { //skip whitespace except \n
		if (!ip->get(ch)) return ct = { Kind::end };
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case';':
	case'\n':
		line_no++;
		return ct = { Kind::print };
	case 0:
		return ct = { Kind::end };
	case 'F':
		return ct = { Kind::fun };
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return ct = { static_cast<Kind>(ch) };
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
	case '.':
		ip->putback(ch);
		*ip >> ct.number_value;
		ct.kind = Kind::number;
		if (record) {
			cout << "I SHOULD SAVED " << endl;
		}
		return ct;
	default:
		if (isalpha(ch)) {
			ct.string_value = ch;
			while (ip->get(ch) && isalnum(ch)){
				ct.string_value += ch;
			}
			ip->putback(ch);
			return ct = { Kind::name };
		}
	}
}

void calculate()
{
	for (;;) {
		ts.get();
 		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		cout << expr(false) << '\n';
		line_no++;
	}
}

double expr(bool get)
{
	double left = term(get);

	for (;;) {
		switch (ts.current().kind) {
		case Kind::plus:
			left += term(true);
			break;
		case Kind::minus:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}

double term(bool get)
{
	double left = prim(get);

	for (;;) {
		switch (ts.current().kind) {
		case Kind::mul:
			left *= term(true);
			break;
		case Kind::div:
			if (auto d = prim(true)) {
				left /= d;
				break;
			}
			return error("divide by 0", line_no);
		default:
			return left;
		}
	}
}

double prim(bool get)
{
	if (get) ts.get();//read next token

	switch (ts.current().kind) {
	case Kind::number:
	{
		double v = ts.current().number_value;
		ts.get();
		return v;
	}
	case Kind::name:
	{
		double& v = table[ts.current().string_value];
		if (ts.get().kind == Kind::assign) v = expr(true);
		return v;
	}
	case Kind::fun:
	{
		cout << "Inside selection.." << endl;
		auto e = expr(true);
		table["test"] = e;
		return e;
	}
	case Kind::minus:
		return -prim(true);
	case Kind::lp:
	{
		auto e = expr(true);
		if (ts.current().kind != Kind::rp) return error("')' expected", line_no);
		ts.get(); // eat the (
		return e;
	}
	default:
		return error("primary expected", line_no);
	}
}




int main()
{
	table["pi"] = 3.1415926535897932385;
	calculate();

	return no_of_errors;
}
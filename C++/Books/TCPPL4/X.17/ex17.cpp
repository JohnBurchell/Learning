//Ex1 - Errors in Date 16.2.3 & 16.2.10
//Error #1 y uninitialised?
//Two errors 
class Date {

	int d, m, y;

public:
	Date& add_year(int n);
};

Date& Date::add_year(int n)
{

	if (d == 29 && m == 2) {
		d = 1;
		m = 3;
	}
	y += n;
	return *this;
}
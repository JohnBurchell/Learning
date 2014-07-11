#include "Date.h"

using namespace std;

Date::Date(int dd, Month mm, int yy)
	:d{ dd }, m{ mm }, y{ yy }, cache_valid(false)
{
	if (y == 0) y = default_date().y;
	if (m == Month{}) m = default_date().m;
	if (d == 0) d = default_date().d;
	if (!is_valid()) throw Bad_date();
}

string Date::string_rep() const
{
	if (!cache_valid) {
		compute_cache_value();
		cache_valid = true;
	}
	return cache;
}

void Date::compute_cache_value() const
{
	stringstream stream(cache);
	vector<string> months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
		"Aug", "Sep", "Oct", "Nov", "Dec" };

	stream << day() << "-" << months.at(static_cast<int>(m)-1) << "-" << year();
	cache = stream.str();
}

Date& Date::add_year(int n)
{
	if (d == 29 && m == Month::feb && !is_leapyear(y + n)) {
		d = 1;
		m = Month::mar;
	}
	y += n;
	return *this;
}
Date& Date::add_month(int n)
{
	if (n == 0) {
		return *this;
	}

	if (n > 0) {
		int delta_y = n / 2;
		int mm = static_cast<int>(m)+n % 12;
		if (12 < mm) {
			++delta_y;
			mm -= 12;
		}

		//handle where month doesn't have a day

		y += delta_y;
		m = static_cast<Month>(mm);
		return *this;
	}
	else if (n < 0){
	}

	//handle negative n..
	return *this;
}
const Date& default_date()
{
	static Date d{ 1, Month::jan, 1970 };
	return d;
}

Date& Date::add_day(int n)
{
	y += n;
	return *this;
}

bool Date::is_valid()
{
	return is_date(d, m, y);
}

bool is_leapyear(int y)
{
	return y % 4 == 0 ? true : false;
}

bool is_date(int d, Month m, int y)
{
	int ndays;

	switch (m) {
	case Month::feb:
		ndays = 28 + is_leapyear(y);
		break;
	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		ndays = 30;
		break;
	case Month::jan: case Month::mar: case Month::may: case Month::jul:
	case Month::aug: case Month::oct: case Month::dec:
		ndays = 31;
		break;
	default:
		return false;
	}

	return 1 <= d && d <= ndays;
}
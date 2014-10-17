#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*
--------------------------------------------------------------------
Ex2 - Complete Date:

I'm going to come back to this later, the implementations in the
book are all over the place so i'm really not sure which one we're
supposed to be doing. It's VERY unclear.
--------------------------------------------------------------------
*/

enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

class Date {

public:

	class Bad_date {};

	explicit Date(int dd = {}, Month mm = {}, int yy = {});

public:
	int day() const { return d; };
	Month month() const { return m; };
	int year() const { return y; };

	std::string string_rep() const;
	void char_rep(char s[], int max) const;

	Date& add_year(int n);
	Date& add_month(int n);
	Date& add_day(int n);

private:
	bool is_valid();
	int d, y;
	Month m;

	mutable bool cache_valid;
	mutable std::string cache;
	void compute_cache_value() const;

};

int diff(Date a, Date b);
bool is_leapyear(int y);
bool is_date(int d, Month m, int y);
const Date& default_date();
Date next_weekday(Date d);
Date next_saturday(Date d);


#endif
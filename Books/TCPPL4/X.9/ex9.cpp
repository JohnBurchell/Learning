#include <iostream>
#include <string>
#include <array>




void ex_1() 
{
	//Largest to smallest
	struct exercise {
		long double ld;
		long l;
		double d;
		int i;
		bool b;
		char c;

	};
}
void ex_2()
{
	//Array version
	std::array<std::array<char, 10>, 12> months = {"January", "Feburary", "March", "April", "May", "June", "Jully", "August", "September", "October", "November", "December"};
	std::array<int, 12> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	//Struct version
	struct Day {
		std::array<char, 10> month;
		int days;
	};

	std::array<Day, 12> months_structs = {{
		{"January", 31},
		{"Feburary", 29},
	    {"March", 31},
	    {"April", 30},
	    {"May", 31},
		{"June", 30},
	    {"Jully", 31},
	    {"August", 31},
	    {"September", 30},
	    {"October", 31},
	    {"November", 30},
	    {"December", 31}
	}};

	std::cout << "Array Version: " << std::endl;
	
	std::array<std::array<char, 10>, 12>::const_iterator months_iter = months.begin();
	std::array<int, 12>::const_iterator days_iter = days.begin();

	while(months_iter != months.end()) {

		for(auto& c : *months_iter){
			std::cout << c;
		}
		std::cout << *days_iter << std::endl;

		++months_iter;
		++days_iter;
	}

	std::cout << "\n\nStruct Version: " << std::endl;

	std::array<Day, 12>::const_iterator struct_iter = months_structs.begin();

	while(struct_iter != months_structs.end()) {

		for(auto& c: struct_iter->month) {
			std::cout << c;
		}
		std::cout << struct_iter->days << std::endl;
		++struct_iter;
	}



}
void ex_3()
{
	/*
		Some examples that i found were odd.

		One that made some sense was:

		int i = sizeof(i);

	*/
}

struct Date 
{
	int day;
	int year;
	std::string month;
	//Default
	Date() :
		day(1),
		month("January"),
		year(1970)
	{};
	//Takes args
	Date(const int& d, const std::string& str, const int& y) :
		day(d),
		year(y),
		month(str)
	{};
		
};

std::ostream& operator<<(std::ostream& os, Date& d) {

	std::cout << "Date is : " << d.day << "-" << d.month << "-" << d.year << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Date& d) {

	std::cout << "Please input a date" << std::endl;
	is >> d.day >> d.month >> d.year;
	return is;
}

void ex_4()
{
	Date today;
	Date tomorrow(10,"June",2014);

	std::cout << tomorrow;
	std::cin >> today;
	std::cout << today;

}

enum class Season 
{ spring, summer, autumn, winter };

Season operator++(Season& s)
{
	switch (s) {
	case Season::spring:
		s = Season::summer;
		break;
	case Season::summer:
		s = Season::autumn;
		break;
	case Season::autumn:
		s = Season::winter;
		break;
	case Season::winter:
		s = Season::spring;
		break;
	}
	return s;
}

Season operator--(Season& s)
{
	switch (s) {
	case Season::spring:
		s = Season::winter;
		break;
	case Season::summer:
		s = Season::spring;
		break;
	case Season::autumn:
		s = Season::summer;
		break;
	case Season::winter:
		s = Season::autumn;
		break;
	}
	return s;
}

std::istream& operator>>(std::istream& is, Season& s)
{
	std::string str;
	std::cout << "Please enter the season" << std::endl;
	is >> str;

	if(str == "spring"){
		s = Season::spring;
	}
	else if(str == "summer"){
		s = Season::summer;
	}
	else if(str == "autumn"){
		s = Season::autumn;
	}
	else if(str == "winter"){
		s = Season::winter;
	}
	else {
		std::cout << "Incorrect month given, ignoring!" << std::endl;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Season s)
{
	switch (s) {

	case Season::spring:
		std::cout << "The season is spring, time to grow!" << std::endl;
		break;
	case Season::summer:
		std::cout << "The season is summer, aww yeah!" << std::endl;
		break;
	case Season::autumn:
		std::cout << "The season is autumn, it's getting colder!" << std::endl;
		break;
	case Season::winter:
		std::cout << "The season is winter, time to get warm!" << std::endl;
		break;
	}
	return os;
}

void ex_5()
{
	Season now = Season::spring;
	std::cout << now << std::endl;
	++now;
	std::cout << now << std::endl;
	++now;
	++now;
	--now;
	std::cout << now << std::endl;
	std::cin >> now;
	std::cout << now << std::endl;

	//------------------NOT IMPLEMENTED FINAL STEP, COME BACK FOR THIS LATER!----------------
}

int main() 
{
	ex_2();
	ex_4();
	ex_5();
	system("pause");
}


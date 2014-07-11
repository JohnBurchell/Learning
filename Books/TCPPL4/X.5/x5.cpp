#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void readInput();
void readInput2();
void intVec();
void stringVec();
void ostreamWriter();
void istreamReader();

template<class C>
void const printVec(const C& c);
template<class C>
void sortVec(C& c);


class Entry
{

public:

	std::string name;
	int age;

};

//Overloaded output operator, takes stream ref and an Entry ref as arguemtns, Entry is const
//As we don't plan on changing it.
std::ostream& operator<<(std::ostream& os, const Entry& e);
std::istream& operator>>(std::istream& is, Entry& e);

int main() 
{

	//readInput();
	//readInput2();
	intVec();
	stringVec();
	ostreamWriter();
	istreamReader();
}

void readInput2()
{
	std::cout << "Please enter a name, followed by an age" << std::endl;

	for(Entry ent; std::cin>>ent;) {
		std::cout << ent << "\n";
	}
}

void readInput() 
{

	std::string name;
	int age;

	std::cout << "Please enter a name, followed by an age" << std::endl;
	std::cin >> name;
	std::cin >> age;

	std::cout << "You entered " << name << " with the age of " << age << std::endl;
}

//Overloaded implementation of outstream
std::ostream& operator<<(std::ostream& os, const Entry& e) 
{
	return os << "{\"" << e.name << "\"," << e.age << "}\n";
}

//Overloaded implementation of isntream
std::istream& operator>>(std::istream& is, Entry& e) 
{
	char c, c2;
	//check for leading {" for pair.
	if(is >> c && c == '{' && is>>c2 && c2 == '"') {
		std::string name;
		//While input and not equal comma...
		while(is.get(c) && c != '"') {
			name += c;

		}

		//Comma found, number coming now
		if(is >> c && c == ',') {
			int number = 0;
			if(is >> number>>c && c =='}'){
				e = {name, number};
				return is;
			}
		}
	}

	std::cout << "Error with reading in\n";
	return is;
}

void intVec() 
{
	std::vector<int> ints{5, 9, -1, 200, 0};
	sortVec(ints);
}

void stringVec() 
{
	std::vector<std::string> strings{"Kant","Plato","Aristotle","Kierkegard","Hume"};
	sortVec(strings);
}

//Take collection and sort it
template<class C>
void sortVec(C &vec) 
{
	std::cout << "\nPre sort: \n";
	printVec(vec);

	std::sort(vec.begin(), vec.end());

	std::cout << "\npost sort: \n";
	printVec(vec);
}

//Take collection and print it
template<class C>
void const printVec(const C &vec) 
{
	for(const auto val: vec) {
		std::cout << val << " ";
	}
}

void ostreamWriter() {

	std::ofstream myFile;
	std::cout << "\nStarting writing\n";
	myFile.open("Output.txt");
	for(int i = 0; i <= 300; i++) {
		myFile << i << "\n";
		std::cout<<".";
	}
	myFile.close();
	std::cout << "\nFinished writing\n";

}

void istreamReader() {

	//Create file reader and string to hold the line.
	std::ifstream myFile;
	std::string line;

	std::cout << "\nStarting reading\n";
	myFile.open("Output.txt");

	if(myFile.is_open()){

		while(getline(myFile, line)){

			std::cout << line;
		}

	} else {

		std::cout << "Error Opening file!" << std::endl;
		exit(1);
	}

	myFile.close();
	std::cout << "\nFinished reading\n";
}
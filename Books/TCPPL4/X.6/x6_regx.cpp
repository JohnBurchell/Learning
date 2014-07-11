#include <iostream>
#include <fstream>
#include <regex>
#include <string>

void genFile();

int main() {
	


	genFile();

	//Create file reader and string to hold the line.
	std::ifstream myFile{"Output.txt"};
	std::string line;

	std::regex pat ("(\\d+)", std::regex_constants::basic);
	std::regex pat2 ("(\w{2}\s*\d{5}(-\d{4})?)");

	int lineno;
	for(std::string line; getline(myFile, line);) {

		std::smatch matches;
		if(std::regex_search(line, matches, pat2))
			std::cout << lineno << ": " << matches[0] << "\n";

	}

	myFile.close();
	std::cout << "Finished reading\n";


}

void genFile() {

	std::ofstream myFile{"Output.txt"};
	for(double i = 0.1; i <= 300; i++) {
		myFile << i << "\n";
	}
	myFile.close();
}
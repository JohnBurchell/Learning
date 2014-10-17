#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include "c_example.h"

using namespace std;

const string path = "D:\\Visual_Studio_2013\\VC\\crt\\src\\";

/*
-------------------------------------------------------------
Ex1, Ex2
-------------------------------------------------------------

Found in the VS install on my windows installation, probably
in the MinGW install location too. On my lux it's in the
common shared libraries area (presumed as i'm not on it). This
applies for external libraries. But with VS you have to include
them manually (as far as i know) which i've done before with the
SFML and SDL libraries.

Windows: D:\Visual_Studio_2013\VC\crt\src
*/

/*
-------------------------------------------------------------
Ex3
-------------------------------------------------------------
*/
fstream* file_finder(const string name)
{
	fstream* file = new fstream;
	vector<string> extensions = { ".cpp", ".c", ".h.cpp" };
	vector<string>::const_iterator iter = extensions.begin();

	file->open(path + name, fstream::in);
	while (!file->is_open() && iter != extensions.end()) {
		file->open(path + name + *iter, fstream::in);
		++iter;
	}
	return file;
}

template <class T, class T2>
bool exists(vector<T>& vec, T2& str)
{
	typedef vector<T>::const_iterator c_iter;
	c_iter start = vec.begin();
	while (start != vec.end()) {
		if (*start == str) {
			return true;
		}
		//Implicit else
		++start;
	}

	return false;
}
int split(const string& str)
{
	vector<string> strs;
	stringstream ss(str);
	string word;
	while (getline(ss, word, ' ')){
		strs.push_back(word);
	}

	return strs.size();
}
void ex3(string location, vector<string>& includes, int count)
{

	fstream* file = new fstream;

	regex reg1{ "(#include) <(.*)>" };
	regex reg2{ "(#include) \"(.*)\"" };
	regex reg3{ "\/\/", regex::basic };
	regex reg4{ "\/[*]" };
	regex reg5{ "\*\/", regex::basic };

	smatch matches;
	string str;

	if (location.compare("") == 0){
		file->open("Source.cpp", fstream::in);
	}
	else {
		file = file_finder(location);
	}
	int comments = 0, non_comments = 0,
		num_words = 0;
	int line = 0;

	while (getline(*file, str)){

		num_words += split(str);
		++line;
		if (regex_search(str, matches, reg3)) {
			++comments;
		}
		else if (regex_search(str, matches, reg4)) {
			++comments;
			while (getline(*file, str)) {
				++line;
				if (regex_search(str, matches, reg5)) {
					++comments;
					break;
				}
				++comments;
			}
		}
		else {
			++non_comments;
		}

		if (regex_search(str, matches, reg1)) {
			string indent(count, ' ');
			cout << location << indent << matches[2] << endl;
			if (!exists(includes, matches[2])){
				includes.push_back(matches[2]);
				//ex3(matches[2], includes, ++count);
			}
		}
		else if (regex_search(str, matches, reg2)) {
			string indent(count, ' ');
			cout << location << indent << matches[2] << endl;
			if (matches[2] != location) {
				includes.push_back(matches[2]);
				//ex3(matches[2], includes, ++count);
			}
		}
	}
	cout << location << " Contains: " << comments << " comments, and : " << non_comments << " non comments." << endl;
	cout << "Totaling " << num_words << " of words." << endl;
	//clean
	delete file;
}

int main()
{
	vector<string> includes;
	ex3("", includes, 0);
	for (int i = 0; i < includes.size(); i++) {
		ex3(includes[i], includes, 1);
	}
	system("pause");
}
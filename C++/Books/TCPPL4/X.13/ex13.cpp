#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <cstdint>

using namespace std;

/*
------------------------------------------------------------------------------------------------------
Ex1
------------------------------------------------------------------------------------------------------
*/
void fun_one(char* c, int& ref);
void(*p_fun_one)(char*, int&);
void take_fun(void *f());
void* return_fun();

//to fun which takes a pointer to char and ref to int returning null
using fun = void(*)(char*, int&);
//End of Ex1

/*
------------------------------------------------------------------------------------------------------
Ex2
------------------------------------------------------------------------------------------------------
*/
//A reference to a function which takes two ints and returns an int
//Not sure of the benefits, perhaps in algorithms and other abstract uses of passing functions around,
//having a typedef / using alias could help in some way?

/*
------------------------------------------------------------------------------------------------------
Ex3 - Hello each command argument
------------------------------------------------------------------------------------------------------
*/
void ex3(char* argv[])
{
	int i = 1;
	while (argv[i] != '\0'){
		cout << "Hello, " << argv[i] << "!" << endl;
		++i;
	}
}
/*
------------------------------------------------------------------------------------------------------
Ex4 - cat
------------------------------------------------------------------------------------------------------
*/
void ex4(char* argv[])
{
	int i = 1;
	string str;

	while (argv[i] != '\0') {
		ifstream file{ argv[i] };
		if (!file) {
			cout << "Couldn't open file: " << argv[i] << endl;
		}
		while (getline(file, str)){
			cout << str << endl;
		}

		i++;
	}
}
/*
------------------------------------------------------------------------------------------------------
Ex5 & 6 see other; c_example.cpp
------------------------------------------------------------------------------------------------------
*/

/*
------------------------------------------------------------------------------------------------------
Ex7 - ssort
------------------------------------------------------------------------------------------------------
*/

struct User {
	const char* name;
	const char* id;
	int dept;
};

vector<User> heads = {

		{ "Ritchie D.M", "dmr", 11271 },
		{ "Sethi R.", "ravi", 11272 },
		{ "Szymanski T.G.", "tgs", 11273 },
		{ "Shryer N.L.", "nls", 11274 },
		{ "Shryer N.L.", "nls", 11275 },
		{ "Kernighan B.W.", "bwk", 11276 }
};

using CFT = int(const void*, const void*);

int comp1(const void* p, const void* q)
{
	return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}

int comp2(const void* p, const void* q)
{
	return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

void ssort(void* base, size_t num, size_t size, CFT cmp)
{
	/*
	Shell sort, knuth

	this doesn't seem to work with vectors, not sure what the idea was even in the book example!
	*/

	for (int gap = num / 2; 0 < gap; gap /= 2){
		for (int i = gap; i != num; i++)
			for (int j = i - gap; 0 <= j; j -= gap) {
			char* b = static_cast<char*>(base);
			char* pj = b + j*size;
			char* pjg = b + (j + gap)*size;
			if (cmp(pjg, pj) < 0) {
				for (int k = 0; k != size; k++){
					char temp = pj[k];
					pj[k] = pjg[k];
					pjg[k] = temp;
				}
			}
			}
	}
}

void print_id(vector<User>& v)
{
	for (auto& x : v) {
		cout << x.name << "\t" << x.id << "\t" << x.dept << endl;
	}
}

/*
------------------------------------------------------------------------------------------------------
Ex8 - Tree
------------------------------------------------------------------------------------------------------
*/
struct Tnode {
	const char** c_word;
	Tnode* left;
	Tnode* right;
};

void new_node(const char* str, Tnode* leaf)
{
	if (strcmp(*leaf->c_word, str) <= 0) {
		if (leaf->left != nullptr){
			new_node(str, leaf->left);
		}
		else{
			leaf->left = new Tnode{ new const char*{ str }, nullptr, nullptr };
		}
	}
	else if (strcmp(*leaf->c_word, str) > 0) {
		if (leaf->right != nullptr){
			new_node(str, leaf->right);
		}
		else{
			leaf->right = new Tnode{ new const char*{ str }, nullptr, nullptr };
		}
	}
}

void print_tree(const Tnode* leaf)
{
	if (leaf != nullptr) {
		cout << *leaf->c_word << endl;
		print_tree(leaf->left);
		print_tree(leaf->right);
	}
}

bool cmp(const char* a, const char* b)
{
	return strcmp(a, b) < 0;
}

void print_alpha(Tnode& leaf)
{
	/*
	Breadth First Search (BFS) - http://en.wikipedia.org/wiki/Breadth-first_search
	*/
	vector<const char*> words;
	queue<Tnode> nodes;

	//Queue root node.
	nodes.push(leaf);

	//While not empty, examine all elements
	while (!nodes.empty()){
		//Get first node
		Tnode current = nodes.front();
		//Remove the first element
		nodes.pop();
		//Add children if they're not null
		words.push_back(*current.c_word);

		if (current.left != nullptr){
			nodes.push(*current.left);
		}
		if (current.right != nullptr){
			nodes.push(*current.right);
		}
	}

	cout << "Sorted words" << endl;
	cout << "-----------" << endl;

	//Must use a custom comparator else it'll compare pointer values.
	sort(words.begin(), words.end(), cmp);

	for (auto& x : words) {
		cout << x << endl;
	}
}

/*
------------------------------------------------------------------------------------------------------
Ex9 - 2d Array invert
------------------------------------------------------------------------------------------------------
*/
void invert_2d()
{
	/*
	both are O(n2) at the moment, which is bad :(
	*/
	array<array<int, 4>, 4> arr = { {

			{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 } } };

	int arr_size = arr.size() - 1;

	for (auto&x : arr){
		for (int i = 0; i <= arr_size / 2; i++) {
			int temp = x[i];
			x[i] = x[arr_size - i];
			x[arr_size - i] = temp;
		}
	}

	for (int i = 0; i < arr_size / 2; i++) {
		for (int j = 0; j <= arr_size; j++){
			int temp = arr[i][j];
			arr[i][j] = arr[arr_size - i][j];
			arr[arr_size - i][j] = temp;
		}
	}

	for (auto& x : arr) {
		for (auto& y : x){
			cout << y;
		}
		cout << "\n";
	}


}

/*
------------------------------------------------------------------------------------------------------
Ex10 - Basic Encryption
------------------------------------------------------------------------------------------------------
*/
//Forward decl
void decryption(string& message);

void encryption(char* argv[])
{
	cout << "Enter the encryption key\n";
	string key;
	getline(cin, key);
	string message;
	cout << "Enter the message:\n";
	getline(cin, message);

	if (key.size() < 1 || message.size() < 1) {
		cout << "No key or message entered. No encryption needed" << endl;
		return;
	}

	for (auto& x : message) {
		static unsigned int count = 0;
		x = x^key[count];
		count = (++count) % key.size();
	}
	cout << message << endl;
	cout << "----Encryption completed!----" << endl;
	decryption(message);
}

void decryption(string& message)
{
	cout << "Enter the decryption key\n";
	string key;
	getline(cin, key);

	for (auto& x : message) {
		static unsigned int count = 0;
		x = x^key[count];
		count = (++count) % key.size();
	}
	cout << message << endl;
	cout << "----Decryption completed!----" << endl;

	cout << 1 - (22 % 26) << endl;
}

void solitare(string& message)
{
	//Put the text into 5 letter forms
	//Gen keystream (random letters) to same len of message
	//convert ciphertext to numbers (og message) (-48 etc)
	//convert keystream into numbers
	//subtract keystream from ciphertext, mod 26

	//https://www.schneier.com/solitaire.html
}

/*
------------------------------------------------------------------------------------------------------
Ex11 - TEA time - http://143.53.36.235:8080/tea.htm
------------------------------------------------------------------------------------------------------
*/

void encipher(uint32_t* v, uint32_t* k)
{
	uint32_t v0 = v[0], v1 = v[1], sum = 0, i;
	uint32_t delta = 0x9e3779b9;
	uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];
	for (i = 0; i < 32; i++){
		sum += delta;
		v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
	}

	v[0] = v0; v[1] = v1;
}

void decipher(const unsigned long *const v, unsigned long *const w, const unsigned long * const k);
/*
------------------------------------------------------------------------------------------------------
Ex13 - I'd write them inside out and in the form of typedefs, like i've used above
------------------------------------------------------------------------------------------------------
*/
/*
------------------------------------------------------------------------------------------------------
Ex14 - Things are use in many many ways, too many to write out here!
------------------------------------------------------------------------------------------------------
*/
/*
------------------------------------------------------------------------------------------------------
Ex15 - The definitions could be written as constexpr's instead?
------------------------------------------------------------------------------------------------------
*/

int main(int argc, char* argv[])
{
	if (argc > 0){
		ex3(argv);
		ex4(argv);
	}

	Tnode tree = { new const char*{ "John" }, nullptr, nullptr };

	new_node("Aligator", &tree);
	new_node("Mikis", &tree);
	new_node("Tim", &tree);
	new_node("RangerDangerreallylongwordthatmightoverflowsomethingatsomepoint", &tree);
	new_node("Chris", &tree);

	print_tree(&tree);
	cout << "-----------" << endl;
	print_alpha(tree);

	invert_2d();

	encryption(argv);

	system("pause");

	return 0;
}

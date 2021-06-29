#include <iostream>
#include <chrono>

#include "Problem_1.h"

using std::list;
using std::make_pair;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using std::endl;

void Problem_1(list<pair<int, int>>& CharactersAndFrequency, vector<int>& Binary)
{
	auto start = std::chrono::high_resolution_clock::now();

	Huffman Hf;
	
	Leaf* Tree = Hf.BuildTree(CharactersAndFrequency);

	string Decoded = Hf.DecodeText(Tree, Binary);

	int Frequency = Tree->GetFreq();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(duration);

	cout << "Decoded text: " << Decoded << endl;
	cout << "Frequency: " << Frequency << endl;
	cout << "Duration: " << f_secs.count() << " s" << endl;
}

int main()
{
	// Problem 1
	list<pair<int, int>> C_F1;
	list<pair<int, int>> C_F2;

	C_F1.push_back(make_pair(32, 1));
	C_F1.push_back(make_pair(72, 1));
	C_F1.push_back(make_pair(46, 1));
	C_F1.push_back(make_pair(100, 1));
	C_F1.push_back(make_pair(87, 1));
	C_F1.push_back(make_pair(101, 1));
	C_F1.push_back(make_pair(108, 3));
	C_F1.push_back(make_pair(111, 2));
	C_F1.push_back(make_pair(114, 1));

	vector<int> Binary1({ 1,1,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,0,
							 1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1 });

	cout << "Scenario 1:" << endl;
	Problem_1(C_F1, Binary1);

	C_F2.push_back(make_pair(32, 3));
	C_F2.push_back(make_pair(44, 1));
	C_F2.push_back(make_pair(46, 1));
	C_F2.push_back(make_pair(83, 1));
	C_F2.push_back(make_pair(97, 1));
	C_F2.push_back(make_pair(99, 1));
	C_F2.push_back(make_pair(101, 2));
	C_F2.push_back(make_pair(104, 1));
	C_F2.push_back(make_pair(105, 1));
	C_F2.push_back(make_pair(107, 1));
	C_F2.push_back(make_pair(110, 1));
	C_F2.push_back(make_pair(111, 1));
	C_F2.push_back(make_pair(114, 1));
	C_F2.push_back(make_pair(116, 4));
	C_F2.push_back(make_pair(121, 1));

	vector<int> Binary2({ 0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,
			0,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,0,
			1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1 });

	cout << endl << "Scenario 2:" << endl;

	Problem_1(C_F2, Binary2);

	return 0;
}
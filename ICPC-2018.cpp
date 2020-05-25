#include <iostream>

#include "Problem_1.h"

void Problem_1()
{
	std::list<std::pair<int, int>> CharactersAndFrequency1;
	std::list<std::pair<int, int>> CharactersAndFrequency2;

	Huffman Test;
	{
		CharactersAndFrequency1.push_back(std::make_pair(32, 1));
		CharactersAndFrequency1.push_back(std::make_pair(72, 1));
		CharactersAndFrequency1.push_back(std::make_pair(46, 1));
		CharactersAndFrequency1.push_back(std::make_pair(100, 1));
		CharactersAndFrequency1.push_back(std::make_pair(87, 1));
		CharactersAndFrequency1.push_back(std::make_pair(101, 1));
		CharactersAndFrequency1.push_back(std::make_pair(108, 3));
		CharactersAndFrequency1.push_back(std::make_pair(111, 2));
		CharactersAndFrequency1.push_back(std::make_pair(114, 1));

		std::vector<int> Binary({ 1,1,0,0,0,1,1,1,1,0,1,0,0,0,
			1,1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1 });

		Leaf* Tree = Test.BuildTree(CharactersAndFrequency1);

		std::string Decoded = Test.DecodeText(Tree, Binary);
		int Frequency = Tree->GetFreq();

		std::cout << "Scenario 1:" << std::endl;
		std::cout << "Decoded text: " << Decoded << std::endl;
		std::cout << "Frequency: " << Frequency << std::endl;
	}

	{
		CharactersAndFrequency2.push_back(std::make_pair(32, 3));
		CharactersAndFrequency2.push_back(std::make_pair(44, 1));
		CharactersAndFrequency2.push_back(std::make_pair(46, 1));
		CharactersAndFrequency2.push_back(std::make_pair(83, 1));
		CharactersAndFrequency2.push_back(std::make_pair(97, 1));
		CharactersAndFrequency2.push_back(std::make_pair(99, 1));
		CharactersAndFrequency2.push_back(std::make_pair(101, 2));
		CharactersAndFrequency2.push_back(std::make_pair(104, 1));
		CharactersAndFrequency2.push_back(std::make_pair(105, 1));
		CharactersAndFrequency2.push_back(std::make_pair(107, 1));
		CharactersAndFrequency2.push_back(std::make_pair(110, 1));
		CharactersAndFrequency2.push_back(std::make_pair(111, 1));
		CharactersAndFrequency2.push_back(std::make_pair(114, 1));
		CharactersAndFrequency2.push_back(std::make_pair(116, 4));
		CharactersAndFrequency2.push_back(std::make_pair(121, 1));

		std::vector<int> Binary({ 0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,
			0,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,0,
			1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,1,1,0,0,1,0,0,1,1 });

		Leaf* Tree = Test.BuildTree(CharactersAndFrequency2);

		std::string Decoded = Test.DecodeText(Tree, Binary);
		int Frequency = Tree->GetFreq();

		std::cout << std::endl << "Scenario 2:" << std::endl;
		std::cout << "Decoded text: " << Decoded << std::endl;
		std::cout << "Frequency: " << Frequency << std::endl;
	}
}

int main()
{
	// Problem 1
	Problem_1();

	return 0;
}
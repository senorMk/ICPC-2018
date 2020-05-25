#pragma once

#include <list>
#include <vector>
#include <algorithm>

struct Leaf;

struct Node
{
private:
	int  Frequency = 0;

	Node* LeftNode = nullptr, * RightNode = nullptr;
	Leaf* LeftChild = nullptr, * RightChild = nullptr;

public:
	void SetLeftChild(Leaf* left, int freq) { LeftChild = left; Frequency += freq; }
	void SetRightChild(Leaf* right, int freq) { RightChild = right; Frequency += freq; }
	void SetLeftNode(Node* left) { LeftNode = left; Frequency += left->GetFrequency(); }
	void SetRightNode(Node* right) { RightNode = right; Frequency += right->GetFrequency(); }

	Leaf* GetLeftChild() { return LeftChild; }
	Leaf* GetRightChild() { return RightChild; }
	Node* GetLeftNode() { return LeftNode; }
	Node* GetRightNode() { return RightNode; }

	int GetFrequency() { return Frequency; }
};

struct Leaf : public Node
{
public:
	std::string Label;
	char ASCII_C;
	int  ASCII_Code = 0;

	int GetFreq() { return GetFrequency() + Frequency; }

	int GetASCIITotal()
	{
		int TotalASCII = ASCII_Code;
		if (GetLeftChild())TotalASCII += GetLeftChild()->ASCII_Code;
		if (GetRightChild())TotalASCII += GetRightChild()->ASCII_Code;

		return TotalASCII;
	}
	void SetFreq(int freq) { Frequency = freq; }

private:
	int  Frequency = 0;
};

struct GreaterByASCII
{
	bool operator()(Leaf* A, Leaf* B)
	{
		if (A->ASCII_Code <= B->ASCII_Code)
			return true;

		return false;
	}
};

class Huffman
{
public:
	Huffman() {}
	~Huffman()
	{
		// memory
		for (auto leaf : Cleanup)
			if (leaf) { delete leaf; }
	}

	std::string DecodeText(Leaf* Tree, std::vector<int>& Binary)
	{
		std::string DecodedText;

		Leaf* RootLevel = Tree;

		for (auto bit : Binary)
		{
			int Code = Tree->ASCII_Code;
			if (bit == 0) // take left
			{
				if (Tree->GetLeftNode())
					Tree = (Leaf*)Tree->GetLeftNode();
				else
					Tree = (Leaf*)Tree->GetLeftChild();
			}
			if (bit == 1) // take right
			{
				if (Tree->GetRightNode())
					Tree = (Leaf*)Tree->GetRightNode();
				else
					Tree = (Leaf*)Tree->GetRightChild();
			}
			if (Tree->ASCII_Code > 0)
			{
				DecodedText += Tree->ASCII_C;
				Tree = RootLevel;
			}
		}

		return DecodedText;
	}

	Leaf* BuildTree(std::list<std::pair<int, int>>& CharactersAndFrequency)
	{
		// Initially, we'll have a list of leafs
		std::vector<Leaf*> ListOfLeaves;
		std::vector<Leaf*> SortedListOfLeaves;

		int HighestFreq = 0;
		for (auto entry : CharactersAndFrequency)
		{
			Leaf* NewL = new Leaf;
			Cleanup.push_back(NewL);

			NewL->ASCII_C = entry.first;
			NewL->ASCII_Code = entry.first;
			NewL->SetFreq(entry.second);

			ListOfLeaves.push_back(NewL);

			if (entry.second > HighestFreq)
				HighestFreq = entry.second;
		}

		// Sort the list by increasing frequency, breaking ties by increasing ASCII code.
		for (int f = 1; f <= HighestFreq; f++)
		{
			std::vector<Leaf*> CurrentFreqList;
			for (auto leaf : ListOfLeaves)
			{
				if (leaf->GetFreq() == f)
					CurrentFreqList.push_back(leaf);
			}

			std::sort(CurrentFreqList.begin(), CurrentFreqList.end(), GreaterByASCII());
			for (auto Vleaf : CurrentFreqList)
				SortedListOfLeaves.push_back(Vleaf);
		}

		// 1. Remove the first two entries from the list, call them X and Y (in that order)
		// 2. Create a new tree by creating a new non-leaf node, and making X and Y its left
		//    and right children respectively.
		// 3. Insert the newly created tree into the list immediately after all nodes that
		//    have a strictly lower frequency than the new node.
		while (SortedListOfLeaves.size() > 1)
		{
			Leaf* node_ = new Leaf;
			Cleanup.push_back(node_);

			// X and Y
			auto X = *SortedListOfLeaves.begin();
			auto Y = *(SortedListOfLeaves.begin() + 1);

			if (X->ASCII_Code == 0) // if node
				node_->SetLeftNode(X);
			else // else leaf
				node_->SetLeftChild(X, X->GetFreq());

			if (Y->ASCII_Code == 0) // if node
				node_->SetRightNode(Y);
			else // else leaf
				node_->SetRightChild(Y, Y->GetFreq());

			// Erase the first two elements
			SortedListOfLeaves.erase(SortedListOfLeaves.begin());
			SortedListOfLeaves.erase(SortedListOfLeaves.begin());

			// Determine insertion point i.e. immediately larger frequency
			// Set the insertion point to the end by default incase we can't find a good spot to
			// insert it.
			auto InPoint = SortedListOfLeaves.end();

			for (auto it = SortedListOfLeaves.begin(); it != SortedListOfLeaves.end(); it++)
			{
				if ((*it)->GetFreq() >= node_->GetFreq())
				{
					InPoint = it;
					break;
				}
			}
			SortedListOfLeaves.insert(InPoint, node_);
		}

		return *SortedListOfLeaves.begin();
	}

private:
	std::list<Leaf*> Cleanup;
};

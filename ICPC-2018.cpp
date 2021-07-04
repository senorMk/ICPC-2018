#include <iostream>
#include <chrono>

#include "Problem_A.h"
#include "Problem_B.h"
#include "Problem_C.h"
#include "Problem_D.h"

using std::list;
using std::make_pair;
using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;
using std::endl;

void Problem_A()
{
	int C = 0;
	cout << "Enter the number of characters to be used in the record: i.e. C: ";
	cin >> C;
	if (C < 2) { C = 2; }

	list<pair<int, int>> c_list;

	for (int i = 0; i < C; i++)
	{
		int O;
		int F;
		cout << "Enter the ASCII code O that appears F times: i.e. O F: ";
		cin  >> O >> F;
		c_list.push_back(make_pair(O, F));
	}

	vector<int> Binary;

	while (true)
	{
		int b = 0;
		cout << "Enter the encoded binary form: i.e. 1, -1 to end entry: ";
		cin  >> b;

		if (b == -1)
			break;

		Binary.push_back(b);
	}

	auto start = std::chrono::high_resolution_clock::now();

	Huffman Hf;
	
	std::vector<Leaf*> Vec = Hf.BuildTree(c_list);

	Leaf* Tree = *Vec.begin();

	string Decoded = Hf.DecodeText(Tree, Binary);

	int Frequency = Tree->GetFreq();

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(duration);

	cout << "Decoded text: " << Decoded << endl;
	cout << "Frequency: " << Frequency << endl;
	cout << "Duration: " << f_secs.count() << " s" << endl;
}

void Problem_B()
{
	int a, b, c, d, Q;
	cout << "Enter the four coefficients: i.e. a b c d: ";
	cin >> a >> b >> c >> d;
	if (a < 0 || a > pow(10, 9)) { a = 0; }
	if (b < 0 || b > pow(10, 9)) { b = 0; }
	if (c < 0 || c > pow(10, 9)) { c = 0; }
	if (d < 0 || d > pow(10, 9)) { d = 0; }

	cout << "Enter Q: i.e. Q: ";
	cin >> Q;
	if (Q < 1 || Q > 500) { Q = 0; }

	vector<int> n_vec;

	for (int i = 0; i < Q; i++)
	{
		int n;
		cout << "Enter each n: i.e. n.: ";
		cin >> n;
		
		if (n < (int)-pow(10, 9) || n > (int)pow(10, 9)) { n = (int)-pow(10, 9); }
		n_vec.push_back(n);
	}

	auto start = std::chrono::high_resolution_clock::now();

	for (auto n : n_vec)
	{
		int o = F_n(n, a, b, c, d);
		cout << "Output: " << o << endl;
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = stop - start;
	auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(duration);
	cout << "Duration: " << f_secs.count() << " s" << endl;
}

void Problem_C()
{
	int x;
	cout << "Enter the number of standard fertilisers to consider: i.e. x : ";
	cin >> x;
	if (x < 2 || x > 4) { x = 2; }

	vector< Fertilizer> v_fert;

	for (int i = 0; i < x; i++)
	{
		Fertilizer fert;
		cout << "Enter the amount of Nitrogen, Phosphorus and Potassium in each: i.e. a b c : ";
		cin >> fert.n_i >> fert.p_i >> fert.k_i;
		if (fert.n_i < 0 || fert.n_i > 15) { fert.n_i = 0; }
		if (fert.p_i < 0 || fert.p_i > 15) { fert.p_i = 0; }
		if (fert.k_i < 0 || fert.k_i > 15) { fert.k_i = 0; }
		fert.quantity = 1;
		v_fert.push_back(fert);
	}

	int desired_n, desired_p, desired_k;
	cout << "Enter the desired amounts of Nitrogen, Phosphorus and Potassium: i.e. a b c : ";
	cin >> desired_n >> desired_p >> desired_k;
	if (desired_n < 0 || desired_n > 500) { desired_n = 0; }
	if (desired_p < 0 || desired_p > 500) { desired_p = 0; }
	if (desired_k < 0 || desired_k > 500) { desired_k = 0; }

	// Actual ratios
	int Actual_N = 0;
	int Actual_P = 0;
	int Actual_K = 0;
}

void Problem_D()
{
	while (true)
	{
		int turn = 1;
		unsigned long long N = 0;

		cout << "Enter the input number: ";
		cin  >> N;

		if (N == -1)
			break;

		auto start = std::chrono::high_resolution_clock::now();

		while (N != 1)
		{
			// Power of two
			if (PowerOfTwo(N))
			{
				N = N / 2;
			}
			else
			{
				unsigned long long L = N;
				while (!PowerOfTwo(L))
				{
					L = L - 1;
				}
				N = N - L;
			}
			if (N == 1)
			{
				if (turn % 2 == 0)
					cout << "Bob" << endl;
				else
					cout << "Alice" << endl;

				break;
			}
			turn++;
		}

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = stop - start;
		auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(duration);
		cout << "Duration: " << f_secs.count() << " s" << endl;
	}
}

int main()
{
	cout << endl << "Problem A." << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Problem_A();
	
	cout << endl << "Problem B." << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Problem_B();

	cout << endl << "Problem C." << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Problem_C();

	cout << endl << "Problem D." << endl;
	cout << "-----------------------------------------------------------" << endl;

	//Problem_D();

	cout << endl << "Problem E." << endl;
	cout << "-----------------------------------------------------------" << endl;

	return 0;
}
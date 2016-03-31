/*
Main.cpp:
-- Full console program that resolves the problem of uniform capacity baskets and a given amount of balls
-- Resolves multiple instances in single run
-- Contains 
   + Main(),
   + print(),
	-- Prints results
   + input(),
    -- Creates 2D vector of input vals
	--- input[i][0] => 'b' value
	--- input[i][1] => 'n' value
	--- input[i][2] => 'k' value
   + recursiveBasketing() functions
	-- Recursive 'Divide and Conquer' algorithm for Combination(k,n,b) problem
	-- n baskets able to hold k balls, with b total balls
	-- Information is held in knownVals for dynamic programming usage.
*/
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

vector<vector<int>> input(int &, vector<vector<int>>);
void print(vector<int>);
int recursiveBasketing(vector<vector<int>>&, int, int, int);

int main()
{
	int count = 0;
	vector<vector<int>> arguments;
	arguments = input(count, arguments);
	vector<int> results;
	//int** knownVals;													//2D Array kV[][]; should be kV[n][b] : kV[n][b] == C(n, b)
	for (int i = 0; i < count; i++)
	{
		vector<vector<int>> knownVals;
		int n = arguments[i][1];
		int b = arguments[i][0];
		int k = arguments[i][2];
		//Initialize an array of arrays for this instance;
		//-- Initialize kV[n]
		knownVals.resize(n + 1);
		//-- Setup the kV[n] array so that each [1..n-1] points to a sub-array for [b]
		for (int iterN = 0; iterN < n+1; iterN++)
		{
			knownVals[iterN].resize(b+1);
			for (int iterB = 0; iterB <= b; iterB++)
				knownVals[iterN][iterB] = -1;
		}
		int total = recursiveBasketing(knownVals, k, n, b);
		cout << "Total for (n=" << n << ",k=" << k << ",b=" << b << ") is: " << total << endl;
		results.push_back( recursiveBasketing(knownVals, k, n, b) );
	}

	print(results);

	int hold = 0;
	cin >> hold;
}

int recursiveBasketing(vector<vector<int>> &knownVals, int k, int n, int b)
{

	if (knownVals[n][b] > -1)
		return knownVals[n][b];
	if (n * k < b)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (b == 1)
	{
		return n;
	}
	if (b == 0)
		return 1;
	int total = 0;

	for (int i = 0; i <= k && b >= i; i++)
	{
		total += recursiveBasketing(knownVals, k, n - 1, b - i);
	}
	knownVals[n][b] = total;
	return total;
}

vector<vector<int>> input(int &count, vector<vector<int>> args)
{
	string line;
	ifstream file("input.txt");

	if (file.is_open())
	{
		getline(file, line);
		count = atoi(line.c_str());
		while (getline(file, line))
		{
			vector<int> temp;
			stringstream stream(line);
			int num;
			while (stream >> num)
			{
				temp.push_back(num);
			}

			args.push_back(temp);
		}
	}
	return args;
}

void print(vector<int> results)
{
	ofstream file;
	file.open("output.txt");
	for (unsigned int i = 0; i < results.size(); i++)
	{
		file << results[i] << endl;
	}
}
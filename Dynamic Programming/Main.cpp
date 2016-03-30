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
	--- input[i][0] => 'k' value
	--- input[i][1] => 'n' value
	--- input[i][2] => 'b' value
   + recursiveBasketing() functions
	-- Recursive 'Divide and Conquer' algorithm for Combination(k,n,b) problem
	-- n baskets able to hold k balls, with b total balls
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
int recursiveBasketing(int**&, const int, int, int);


int main()
{
	int count = 0;
	vector<vector<int>> arguments;
	arguments = input(count, arguments);
	vector<int> results;
	int** knownVals;													//2D Array kV[][]; should be kV[n][b] : kV[n][b] == C(n, b)
	for (int i = 0; i < count; i++)
	{
		//Initialize an array of arrays for this instance;
		//-- Initialize kV[n]
		knownVals = new int*[arguments[i][1]];
		//-- Setup the kV[n] array so that each [1..n-1] points to a sub-array for [b]
		for (int j = 0; j < arguments[i][1]; j++)
		{
			knownVals[j] = new int[arguments[i][2]];
			for (int k = 0; k < arguments[i][2]; k++)
				knownVals[j][k] = -1;
		}
		int temp = recursiveBasketing(knownVals, arguments[i][0], arguments[i][1], arguments[i][2]);
		results.push_back(temp);

		//Free subarrays [0..b-1] for kV[][]
		for (int j = 0; j < count; j++)
		{
			delete[] knownVals[j];
		}
		//And again [0..n-1] for kV[][]
		delete[] knownVals;
	}

	print(results);
	int hold = 0;
}

int recursiveBasketing(int** &knownVals, const int k, int n, int b)
{
	if (n * k < b)
		return 0;

	else if (b == 1)
		return n;
	else if (b == 0)
		return 0;
	int total = 0;
	for (int i = 1; i < k; i++)
	{
		//kV[n][b] == knownVals[n-1][b-1], so C(n-1,b-i) == knownVals[n-1-1][b-i-1], or knownVals[n-2][b-i-1]
		//If this is confusing, we can go back and index from [1..n][1..b] instead of [0..n-1][0..b-1]
		if (knownVals[n - 2][b - i - 1] == -1)												//Does not exist in table
			knownVals[n - 2][b - i - 1] = recursiveBasketing(knownVals, k, n - 1, b - i);	//Calc and it in table
		total += knownVals[n - 2][b - i - 1];												//It's in table for sure, so add it to total
	}
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
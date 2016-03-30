#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

vector<vector<int>> input(int &, vector<vector<int>>);
void print(vector<int>);
int C(const int, int, int);


int main()
{
	int count = 0;
	vector<vector<int>> arguments;
	arguments = input(count, arguments);
	vector<int> results;

	for (int i = 0; i < count; i++)
	{
		int temp = C(arguments[i][0], arguments[i][1], arguments[i][2]);
		results.push_back(temp);
	}

	print(results);
}

int C(const int k, int n, int b)
{
	if (n <= 2)
	{
		/*if (k == b)
			return 1;*/
		if (b <= k)
			return b;
		else if (2 * k >= b)
		{
			//Still need to resolve this
			return 0;
		}
		else
			return 0;
	}
	else if (b == 1)
		return n;
	else if (b == 0)
		return 0;
	int total = 0;
	for (int i = 1; i < k; i++)
	{
		total += C(k, n - 1, b - i);
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
	for (int i = 0; i < results.size(); i++)
	{
		file << results[i] << endl;
	}
}
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	string line;
	ifstream file ("input.txt");
	int count = 0;
	vector<vector<int>> arguments;

	if(file.is_open())
	{
		getline(file, line);
		count = atoi(line.c_str());
		while( getline(file, line))
		{
			vector<int> temp;
			stringstream stream(line);
			int num;
			while(stream >> num)
			{
				temp.push_back(num);
			}

			arguments.push_back(temp);
		}
	}

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
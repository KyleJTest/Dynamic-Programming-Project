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

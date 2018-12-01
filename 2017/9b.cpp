#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main()
{
	ifstream in("8a.in");
	
	bool skip = false;
	bool garbage = false;
	
	int rem = 0;
	
	char c;
	while (in >> c)
	{
		if (skip)
		{
			skip = false;
			continue;
		}
		
		if (c == '!')
		{
			skip = true;
			continue;
		}
		
		if (garbage)
		{
			if (c == '>')
			{
				garbage = false;
			}
			else
			{
				rem++;
			}
		}
		else
		{
			if (c == '<')
			{
				garbage = true;
			}
		}
	}
	
	cout << rem << endl;
}

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
	ifstream in("9a.in");
	
	bool skip = false;
	bool garbage = false;
	int depth = 0;
	
	int sum = 0;
	
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
		}
		else
		{
			if (c == '<')
			{
				garbage = true;
			}
			else if (c == '{')
			{
				depth++;
				sum += depth;
			}
			else if (c == '}')
			{
				depth--;
			}
		}
	}
	
	cout << sum << endl;
}

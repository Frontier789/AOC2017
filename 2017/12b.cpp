#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

int main()
{
	map<int,vector<int>> graph;
	
	ifstream in("12a.in");
	
	int from;
	while (in >> from)
	{
		string line;
		getline(in,line);
		
		stringstream ss(line);
		
		int to;
		while (ss >> to)
		{
			graph[from].push_back(to);
		}
	}
	
	queue<int> sor;
	map<int,bool> color;
	
	int db = 0;
	
	for (auto &beg : graph)
	{
		if (color[beg.first] == 1) continue;
		
		sor.push(beg.first);
		color[beg.first] = 1;
		++db;
		
		while (!sor.empty())
		{
			int cur = sor.front();
			sor.pop();
			
			for (int nxt : graph[cur])
			{
				if (!color[nxt])
				{
					color[nxt] = 1;
					sor.push(nxt);
				}
			}
		}
	}
	
	cout << db << endl;
}

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

int main()
{
	int steps = 386;
	int ntl = 2017;
	
	list<int> ls;
	ls.insert(ls.begin(),0);
	auto it = ls.begin();
	
	for (int i=1;i<=2017;++i)
	{
		for (int j=0;j<steps;++j)
		{
			++it;
			if (it == ls.end())
				it = ls.begin();
		}
		
		++it;
		
		it = ls.insert(it,i);
	}
	/*
	for (auto v : ls)
	{
		cout << v << " ";
	}
	cout << endl;
	*/
	++it;
	if (it == ls.end())
		it = ls.begin();
	
	cout << *it << endl;
}


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
	
	int siz = 1;
	int nxt = 0;
	int cur = 0;
	
	for (int i=1;i<=50000000;++i)
	{
		if (cur == 0)
			nxt = i;
		
		siz++;
		cur++;
		
		cur += steps;
		
		cur %= siz;
	}
	
	cout << nxt << endl;
}


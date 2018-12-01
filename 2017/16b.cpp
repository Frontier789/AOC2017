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
	vector<int> nameToPos(1000,0);
	string str = "abcdefghijklmnop";
	
	for (int i=0;i<str.size();++i)
	{
		nameToPos[str[i]] = i;
	}
	
	vector<int> in_cache;
	ifstream in("16a.in");
	
	for (char c;in >> c;)
	{
		in_cache.push_back(int(c));
		
		if (c == 'x')
		{
			int a,b;
			in>>a>>b;
			
			in_cache.push_back(a);
			in_cache.push_back(b);
		}
		else if (c == 'p')
		{
			char ac,bc;
			in>>ac>>bc;
			
			in_cache.push_back(int(ac));
			in_cache.push_back(int(bc));
		}
		else if (c == 's')
		{
			int n;
			in>>n;
			
			in_cache.push_back(int(n));
		}
	}
	
	map<string,int> volt;
	
	bool loopfound = false;
	
	for (int k = 0;k<1000000;++k)
	{
		if (!loopfound && volt.find(str) != volt.end())
		{
			loopfound = true;
			int looplen = k - volt[str];
			
			while (k+looplen < 1000000) k+=looplen;
		}
		volt[str] = k;
		
		for (int i=0;i<in_cache.size();++i)
		{
			
			char c = char(in_cache[i]);
			
			if (c == 'x')
			{
				int a = in_cache[++i];
				int b = in_cache[++i];
				
				char ac = str[a],bc = str[b];
				
				str[b] = ac;
				str[a] = bc;
				
				nameToPos[ac] = b;
				nameToPos[bc] = a;
			}
			else if (c == 'p')
			{
				char ac = in_cache[++i];
				char bc = in_cache[++i];
				
				char a = nameToPos[ac],b = nameToPos[bc];
				
				str[b] = ac;
				str[a] = bc;
				
				nameToPos[ac] = b;
				nameToPos[bc] = a;
			}
			else if (c == 's')
			{
				int n = in_cache[++i];
				
				str = str.substr(str.size()-n,n) + str.substr(0,str.size() - n);
		
				for (int i=0;i<str.size();++i)
				{
					nameToPos[str[i]] = i;
				}
			}
		}
	}
	
	cout << str << endl;
}


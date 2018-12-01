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
	map<char,int> nameToPos;
	string str = "abcdefghijklmnop";
	
	for (int i=0;i<str.size();++i)
	{
		nameToPos[str[i]] = i;
	}
	
	ifstream in("16a.in");
	
	char c;
	while (in >> c)
	{
		if (c == 'x')
		{
			int a,b;
			in>>a>>b;
			
			char ac = str[a],bc = str[b];
			
			str[b] = ac;
			str[a] = bc;
			
			nameToPos[ac] = b;
			nameToPos[bc] = a;
		}
		else if (c == 'p')
		{
			char ac,bc;
			in>>ac>>bc;
			
			char a = nameToPos[ac],b = nameToPos[bc];
			
			str[b] = ac;
			str[a] = bc;
			
			nameToPos[ac] = b;
			nameToPos[bc] = a;
		}
		else if (c == 's')
		{
			int n;
			in>>n;
			
			str = str.substr(str.size()-n,n) + str.substr(0,str.size() - n);
	
			for (int i=0;i<str.size();++i)
			{
				nameToPos[str[i]] = i;
			}
		}
	}
	
	cout << str << endl;
}


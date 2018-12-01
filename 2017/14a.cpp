#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define N 256

string knot_hash(string s)
{
	s += (char)17;
	s += (char)31;
	s += (char)73;
	s += (char)47;
	s += (char)23;
	
	int ls[N];
	for (int i=0;i<N;++i)
		ls[i] = i;
	
	int p = 0;
	int skip = 0;
	
	for (int db = 0;db < 64;++db)
	{
		for (int l : s)
		{
			//for (int i : ls) cout << i << " "; cout << endl;
			
			
			for (int i=0;i<l/2;++i)
			{
				int a = (p + i) % N;
				int b = (p + l - i - 1) % N;
				
				swap(ls[a],ls[b]);
			}
			/*
			for (int i : ls) cout << i << " "; cout << endl;
			cout << endl;
			cout << endl;
			*/
			p += l + skip;
			p %= N;
			
			skip++;
		}
	}
	
	string hex = "0123456789abcdef";
	
	string ret;
	
	for (int i=0;i<16;++i)
	{
		int xored = ls[i*16 + 0];
		
		for (int j=1;j<16;++j)
		{
			xored = xored ^ ls[i*16 + j];
		}
		
		ret += hex[xored / 16];
		ret += hex[xored % 16];
	}
	
	return ret;
}

int quadToInt(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	
	return c - 'a' + 10;
}

int main()
{
	string inp = "jxqlasbh";
	
	int used = 0;
	
	for (int r = 0;r<128;++r)
	{
		stringstream ss;
		ss<<inp<<"-"<<r;
		
		string shs = knot_hash(ss.str());
		
		for (char c : shs)
		{
			int a =  quadToInt(c);
			
			bool bs[4] = {bool(a & 0x8),bool(a & 0x4),bool(a & 0x2),bool(a & 0x1)};
			
			for (bool bl : bs)
			{
				if (bl)
				{
					++used;
				}
			}
		}
	}
	cout << used << endl;
}


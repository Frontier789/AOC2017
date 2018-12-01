#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define N 256
//#define N 10

int main()
{
	string lens = "206,63,255,131,65,80,238,157,254,24,133,2,16,0,1,3";
	lens += (char)17;
	lens += (char)31;
	lens += (char)73;
	lens += (char)47;
	lens += (char)23;
	
	int ls[N];
	for (int i=0;i<N;++i)
		ls[i] = i;
	
	int p = 0;
	int skip = 0;
	
	
	for (int db = 0;db < 64;++db)
	{
		for (int l : lens)
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
	
	//for (int i : ls) cout << i << " "; cout << endl;
	
	for (int i=0;i<16;++i)
	{
		int xored = ls[i*16 + 0];
		
		for (int j=1;j<16;++j)
		{
			xored = xored ^ ls[i*16 + j];
		}
		
		cout << hex[xored / 16] << hex[xored % 16];
	}
}

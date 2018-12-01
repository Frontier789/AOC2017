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
	int lens[] = {206,63,255,131,65,80,238,157,254,24,133,2,16,0,1,3};
	
	int ls[N];
	for (int i=0;i<N;++i)
		ls[i] = i;
	
	int p = 0;
	int skip = 0;
	
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
	
	cout << ls[0] * ls[1] << endl;
}

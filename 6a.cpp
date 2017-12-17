#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <map>
#include <set>

using namespace std;


int main()
{
	int t[] = {4,1,15,12,0,9,9,5,5,8,7,3,14,5,12,3};
	
	int sum = 0;
	for (int a : t) sum += a;
	
	auto getState = [&]() -> int64_t {
		int64_t r = 0;
		
		for (int a : t) r = r*sum + a;
		
		return r;
	};
	
	set<int64_t> states;
	int64_t stat = getState();
	
	int cyc = 0;
	while (states.find(stat) == states.end())
	{
		states.insert(stat);
		
		int mx = 0;
		for (int i=0;i<sizeof(t)/sizeof(*t);++i)
		{
			if (t[i] > t[mx]) mx = i;
		}
		
		int s = t[mx];
		t[mx] = 0;
		/*
		cout << mx << "p " << endl;
		cout << s << "d " << endl;
		
		for (int a : t) cout << a << " "; cout << endl;
		*/
		for (int k = (mx+1) % (sizeof(t)/sizeof(*t));s > 0;k = (k+1) % (sizeof(t)/sizeof(*t)))
		{
			t[k]++;
			
			--s;
		}
		/*
		for (int a : t) cout << a << " "; 
		cout << endl;
		cout << endl;
		*/
		stat = getState();
		++cyc;
	}
	
	cout << cyc << endl;
}

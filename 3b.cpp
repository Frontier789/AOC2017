#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	int x=0,y=0;
	int dx=1,dy=0;
	int k = 1;
	int rk = 289326;
	
	map<pair<int,int>,int> val;
	
	auto sumAt = [&](int x,int y) -> int {
		
		if (val[make_pair(x,y)]) return val[make_pair(x,y)];
		
		int r = 0;
		for (int dx=-1;dx<=1;++dx)
		for (int dy=-1;dy<=1;++dy)
			r += val[make_pair(x+dx,y+dy)];
		
		return val[make_pair(x,y)] = r;
	};
	
	val[make_pair(0,0)] = 1;
	
	for (int l=1;;++l)
	{
		for (int i=0;i<l;++i)
		{
			x += dx;
			y += dy;
			++k;
			if (sumAt(x,y) > rk)
			{
				cout << sumAt(x,y) << endl;
				return 0;
			}
		}
		
			 if (dx == 1           ) dx = 0,  dy = 1;
		else if (dx == 0 && dy == 1) dx = -1, dy = 0;
		else if (dx == 0 && dy ==-1) dx = 1,  dy = 0;
		else if (dx ==-1           ) dx = 0,  dy =-1;
		
		for (int i=0;i<l;++i)
		{
			x += dx;
			y += dy;
			++k;
			if (sumAt(x,y) > rk)
			{
				cout << sumAt(x,y) << endl;
				return 0;
			}
		}
		
			 if (dx == 1           ) dx = 0,  dy = 1;
		else if (dx == 0 && dy == 1) dx = -1, dy = 0;
		else if (dx == 0 && dy ==-1) dx = 1,  dy = 0;
		else if (dx ==-1           ) dx = 0,  dy =-1;
	}
}